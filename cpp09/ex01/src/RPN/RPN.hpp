/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:17:20 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/19 11:10:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"

#define IS_OPERATOR(c) ((c) == '+' || (c) == '-' || (c) == '*' || (c) == '/')

#define ADD(x, y) ((x) + (y))
#define SUB(x, y) ((x) - (y))
#define DIV(x, y) ((x) / (y))
#define MUL(x, y) ((x) * (y))

class RPN{
	std::list<long long>	_content;

	void		validInput(std::string &input);
	std::string	getError(std::string &input, int indexError);
	void		normalize(std::string &input);
	void		reversePolishNotation(std::string &input);
	long long	calculator(char c, long long x, long long y);

	template<typename T> 
	T	charTo(char c){
		T	value = 0;
		value += c - '0';
		return value;
	}

	public:
		RPN(std::string &input);
		RPN();
		~RPN();
		RPN&operator=(RPN const &origin);
		RPN(RPN const &origin);
};