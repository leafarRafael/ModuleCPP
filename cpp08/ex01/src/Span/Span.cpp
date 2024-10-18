/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:02:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/18 18:22:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <iterator>
#include <algorithm>

Span::~Span(){}

Span::Span():_list(0), _n(0){}

Span::Span(uint n):_list(0), _n(n){}

Span::Span(const Span & orin):_list(orin._n), _n(orin._n){
}

Span &Span::operator=(const Span & orin){
	if (this != &orin)
	{
		this->_list = orin._list;
		this->_n = orin._n;
	}
	return *this;
}

void	Span::addNumber(int addnbr){
	if (_list.size() == _n)
		throw std::runtime_error("addNumber exception: Number of elements exceeded\n");
	this->_list.push_back(addnbr);
}

int		Span::shortestSpan(int begin, int end){
	std::list<int>	temp(_list);


	temp.sort();
	std::list<int>::iterator	itBegin, itEnd;
	itBegin = std::find(temp.begin(), temp.end(), begin);
	itEnd = std::find(temp.begin(), temp.end(), end);
	int x = 0;
	for (int i = 0; itBegin != itEnd; x++, i++, itBegin++){}
	return x;
}

int		Span::longestSpan(int begin, int end){
	if (begin > end)
		return 0;
	return 1;
}
