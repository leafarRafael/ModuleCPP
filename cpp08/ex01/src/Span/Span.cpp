/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:02:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/19 16:38:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include "Color.hpp"

Span::~Span(){}

Span::Span():_list(0), _n(0){}

Span::Span(uint n):_list(0), _n(n){}

Span::Span(const Span & orin):_list(orin._n), _n(orin._n){
}

Span &Span::operator=(const Span & orin){
	if (this != &orin){
		this->_list = orin._list;
		this->_n = orin._n;
	}
	return *this;
}

void	Span::addNumber(int addnbr){
	if (_list.size() == _n)
		throw std::runtime_error(RED "addNumber exception: Number of elements exceeded.\n" RESET);
	this->_list.push_back(addnbr);
}

int		Span::shortestSpan(){
	if (_list.size() <= 1)
		throw std::runtime_error(RED "shortestSpan() exception: no span can be found.\n" RESET);
	std::list<int>				temp(_list);
	temp.sort();
	std::list<int>::iterator	itNext = temp.begin(), itBegin;
	itBegin = itNext++;
	int value =  *itNext - *itBegin;
	while (itNext != temp.end()){
		if (value >= (*itNext - *itBegin))
			value = *itNext - *itBegin;
		itNext++;
		itBegin++;
	}
	return value;
}

int		Span::longestSpan(){
	if (_list.size() <= 1)
		throw std::runtime_error(RED "longestSpan() exception: no span can be found.\n" RESET);
	std::list<int>				temp(_list);
	temp.sort();
	return temp.back() - temp.front();
}

void	Span::fillSpan(uint amount){
	if (amount > _n)
		throw std::runtime_error(RED "fillSpan() exception: number of elements greater than capacity.\n" RESET);
	std::srand(std::time(0));
	for(uint i = 0; i < amount; i++)
		addNumber(std::rand() % amount);
}

void	Span::fillSpan(int begin, int end){
	if ((end - begin) > static_cast<int>(_n) || (begin - end) > static_cast<int>(_n))
		throw std::runtime_error(RED "fillSpan() exception: number of elements greater than capacity.\n" RESET);
	int	amount = end - begin;
	if (amount < 0){
		for(int i = begin; i < end; i--)
			addNumber(i);
	}else{
		for(int i = begin; i < end; i++)
			addNumber(i);
	}
}