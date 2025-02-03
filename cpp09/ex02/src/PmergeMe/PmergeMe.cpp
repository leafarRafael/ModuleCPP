/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:28:09 by rbutzke           #+#    #+#             */
/*   Updated: 2025/02/03 13:16:47 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "unistd.h"
#include <iomanip>

PmergeMe::PmergeMe(std::string &input){
	try{
		std::clock_t	startTimeVector, startTimeDeque;
		double			elapsedVector, elapsedDeque;

		normalize(input);
		setConteiner(input);
		std::cout << "Before: ";
		printConteiner(_deque);
		
		startTimeDeque = std::clock();
		if (!isSorted(_deque))
			mergeInsertSort(_deque, _dequePair);
		elapsedDeque = elapsedTime(startTimeDeque);
		
		startTimeVector = std::clock();
		if (!isSorted(_vector))
			mergeInsertSort(_vector, _vectorPair);
		elapsedVector = elapsedTime(startTimeVector);

		std::cout << "After: ";
		printConteiner(_deque);
		std::cout << "Time to process a range of " << _deque.size();
		std::cout <<  " elements with std::deque: [";
		std::cout << std::fixed << std::setprecision(6) << elapsedDeque << "] us.\n";

		std::cout << "Time to process a range of " << _vector.size();
		std::cout <<  " elements with std::vector: [";
		std::cout << std::fixed << std::setprecision(6) << elapsedVector << "] us.\n";
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

void	PmergeMe::setConteiner(std::string &input){
	_vector = split<std::vector<int> >(input, ' ');
	_deque = split<std::deque<int> >(input, ' ');
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe const &origin){*this = origin;}

PmergeMe&PmergeMe::operator=(PmergeMe const &origin){
	if (this != &origin){
		this->_vector = origin._vector;
		this->_deque = origin._deque;
	}
	return *this;
}

double	PmergeMe::elapsedTime(double startTime){
	return ((static_cast<double>(std::clock()) - static_cast<double>(startTime)) / CLOCKS_PER_SEC);
}

void	PmergeMe::normalize(std::string &input){
	for (std::size_t i = 0; i < input.size(); i++){
		if (std::isspace(input[i]))
			input[i] = ' ';
	}
}

bool PmergeMe::isNumeric(std::string &number){
	if (number.empty())
		return true;
	for (std::size_t i = 0; i < number.size(); i++){
		if (number[i] == '-' || number[i] == '+')
			continue; 
		if (not std::isdigit(number[i]))
			return false;
	}
	return true;
}

void PmergeMe::printConteinerPair(std::deque<std::pair<int, int> > 	_dequePair){
	std::deque<std::pair<int, int> >::iterator it = _dequePair.begin();

	for(; it != _dequePair.end(); it++){
		std::cout << it->first << " " << it->second << ' ';
	}
	std::cout << '\n';
}