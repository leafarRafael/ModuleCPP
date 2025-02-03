/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:36:04 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/17 14:39:22 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <dirent.h>
#include <cstdlib>


BitcoinExchange::BitcoinExchange(std::string file){
	if((_bufferInput = getBufferFile(file)).empty())
		throw (std::runtime_error("Input file cannot be empty."));
	if ((_bufferDataBase = getBufferFile("src/BitcoinExchange/data.csv")).empty())
		throw (std::runtime_error("Invalid path to data base."));
	setDataBase(',');
	calculateExchange('|');
}

void	BitcoinExchange::calculateExchange(char delimiter){
	trim(_bufferInput);
	std::istringstream	iss(_bufferInput);
	string				token;
	string				tokenDate;
	string				outDate;
	s_date				date;
	float				value;

	std::getline(iss, token, '\n');
	if (token.find("date") == string::npos
		|| token.find("value") == string::npos 
		|| token.find("|") == string::npos){
		throw (std::runtime_error("first line need: data | value"));
	}
	while (std::getline(iss, token, '\n')) {
		if (not token.empty()){
			tokenDate = getContentBeforeLimiter(token, delimiter);
			outDate = tokenDate;
			if (token == "empty")
				std::cerr << "Error: bad input => " << tokenDate << '\n';
			else if  (validValue(token))
				std::cerr << "Error: bad input => " << token << '\n';
			else if (token[0] == '-')
				std::cerr << "Error: not a positive number => " << token << '\n';
			else{
				try{
					date = parseDateToken(tokenDate);
					value = strtod(token.c_str(), NULL);
					if (value > (double)1000)
						std::cerr << "Error: too large a number.\n";
					else{
						std::cout << outDate + " => " + token + " = ";
						std::cout << value * getValueInDataBase(date);
						std::cout << std::endl;
					}	
				}catch(std::exception &e){
					std::cerr << e.what() << std::endl;
				}
			}
		}
	}
}

float	BitcoinExchange::getValueInDataBase(s_date date){
	if (not _dataBase.count(date.year)){
		if (date.year < 2009)
			date.year = 2009;
		else if (date.year > 2022)
			date.year = 2022;
		else{
			while (not _dataBase.count(date.year))
				date.year--;
		}
	}
	if (not _dataBase[date.year].count(date.month)){
		while (not _dataBase[date.year].count(date.month))
			date.month--;
	}
	if (not _dataBase[date.year][date.month].count(date.day)){
		while (not _dataBase[date.year][date.month].count(date.day))
			date.day--;
	}
	return _dataBase[date.year][date.month][date.day];
}

void	BitcoinExchange::setDataBase(char delimiter){
	trim(_bufferDataBase);
	std::istringstream	iss(_bufferDataBase);
	string				token;
	string				tokenDate;
	s_date				date;

	std::getline(iss, token, '\n');
	if (token.find("date") == string::npos || token.find("exchange_rate") == string::npos)
		throw (std::runtime_error("first line need: data, exchange_rate"));
	while (std::getline(iss, token, '\n')) {
		if (not token.empty()){
			tokenDate = getContentBeforeLimiter(token, delimiter);
			date = parseDateToken(tokenDate);
			if (token == "empty")
				_dataBase[date.year][date.month][date.day] = 0;
			else 
				_dataBase[date.year][date.month][date.day] = strtod(token.c_str(), NULL);
		}
	}
}

s_date	BitcoinExchange::parseDateToken(string &tokenDate){
	s_date			date;
	string			temp = tokenDate;
	int				error = 0;

	error = validDate(tokenDate);
	if (error == NOT_NUMBER)
		throw (std::runtime_error("Date must contain numeric values => " + tokenDate));
	if (error == BAD_FORMAT)
		throw (std::runtime_error("Format must be year-month-day =>" + tokenDate));
	date.year = strTo<unsigned short>(getContentBeforeLimiter(tokenDate, '-'));
	date.month = strTo<unsigned short>(getContentBeforeLimiter(tokenDate, '-'));
	date.day = strTo<unsigned short>(getContentBeforeLimiter(tokenDate, '-'));
	if (not isValidDate(date.year, date.month, date.day))
		throw (std::runtime_error("Bad input => " + temp));
	return date;
}

int	BitcoinExchange::validValue(string value){
	int separator = 0;
	std::size_t index = 0;

	if (value[0] == '-')
		index++;
	for(; index < value.length(); index++){
		if (value[index] == '.')
			separator++;
		else if (!std::isdigit(value[index]))
			return 1;
	}
	if (separator > 1)
		return 2;
	return 0;
}

int	BitcoinExchange::validDate(string date){
	int separator = 0;

	for(std::size_t index = 0; index < date.length(); index++){
		if (date[index] == '-')
			separator++;
		else if (!std::isdigit(date[index]))
			return 1;
	}
	if (separator > 2)
		return 2;
	return 0;
}

std::string	BitcoinExchange::getContentBeforeLimiter(string &token, char delimiter){
	std::size_t pos;
	string		date;

	pos = token.find(delimiter);
	if (pos == string::npos){
		trim(token);
		std::string temp = token;
		token = "empty";
		return temp;
	}
	date = token.substr(0, pos);
	token.erase(0, pos +1);
	trim(date);
	trim(token);
	return date;	
}

bool	BitcoinExchange::isValidDate(int year,int month,int day){
	int monthlen[]={31,28,31,30,31,30,31,31,30,31,30,31};

	if (!year || !month || !day || month>12)
		return 0;
	if (month == 2 && ((!(year % 4) && (year % 100)) || !(year % 400)))
		monthlen[1]++;
	if (day>monthlen[month-1])
		return 0;
	return 1;
}

void	BitcoinExchange::putMap(_map map){
	_map::iterator year;
	std::map<int, std::map<int, float> >::iterator month;
	std::map<int, float>::iterator day;
	
	for(year = map.begin(); year != map.end(); year++){
		for (month = map[year->first].begin(); month != map[year->first].end(); month++){
			for (day = map[year->first][month->first].begin(); day != map[year->first][month->first].end(); day++){
				std::cout << year->first << "/";
				std::cout << month->first << "/";
				std::cout << day->first << " | value: " << day->second;
				std::cout << '\n';
			}
		}
	}
}

string BitcoinExchange::getBufferFile(string file){
	DIR	*directory;

	directory = opendir(file.c_str());
	if (directory != NULL){
		closedir(directory);
		return string();
	}
	std::ifstream buffer(file.c_str(), std::ios::in | std::ios::binary);
	if(!buffer)
		return string();
	return string((std::istreambuf_iterator<char>(buffer)), std::istreambuf_iterator<char>());	
}

void	BitcoinExchange::trim(string &str){
	while(str.size() > 0 && std::isspace(static_cast<unsigned char>(str[0])))
		str.erase(0, 1);
	while(str.size() > 0 && std::isspace(static_cast<unsigned char>(str[str.size() -1])))
		str.erase(str.size() - 1, 1);
}


BitcoinExchange::~BitcoinExchange(){
	_bufferDataBase.clear();
	_bufferInput.clear();
	_dataInput.clear();
	_dataBase.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &origin){
	*this = origin;
}

BitcoinExchange&BitcoinExchange::operator=(const BitcoinExchange &origin){
	if (this != &origin){
		this->_bufferDataBase = origin._bufferDataBase;
		this->_bufferInput = origin._bufferInput;
		this->_dataInput = origin._dataInput;
		this->_dataBase = origin._dataBase;
	}
	return *this;
}

s_date::s_date(): year(0), month(0), day(0){}