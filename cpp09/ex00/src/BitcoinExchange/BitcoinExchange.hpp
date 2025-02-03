/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:23:45 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/17 14:36:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <iomanip>

typedef std::string						string;
typedef std::map<int, std::map<int, std::map<int, float> > > _map;

#define NOT_NUMBER 1
#define BAD_FORMAT 2

struct s_date{
	unsigned short year, month, day;
	s_date();
};

class BitcoinExchange{
	private:
		string		_bufferDataBase, _bufferInput;
		_map		_dataInput, _dataBase;

		void		setDataBase(char delimiter);
		s_date		parseDateToken(string &token);
		string		getContentBeforeLimiter(string &token, char delimiter);

		void		trim(string &str);
		int			validValue(string value);
		int			validDate(string date);
		int			strToInt(string	value);
		string		getBufferFile(string file);


		float		getValueInDataBase(s_date date);
		void		calculateExchange(char delimiter);
		bool		isValidDate(int year,int month,int day);

		void		putMap(_map map);
		template<typename T>
		T	strTo(std::string str){
			T					value;

			std::istringstream	iss(str);
			iss >> value;
			return value;
		}

	public:
		BitcoinExchange(string file);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &origin);
		BitcoinExchange&operator=(BitcoinExchange const &origin);

};