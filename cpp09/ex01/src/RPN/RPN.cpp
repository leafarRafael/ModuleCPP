/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:28:09 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/18 11:57:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>
#include <sstream>

RPN::RPN(std::string &input){
	try{
		validInput(input);
		normalize(input);
		reversePolishNotation(input);
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

void	RPN::validInput(std::string &input){
	int	operat = 0, operand = 0;

	for (std::size_t i = 0; i < input.length(); i++){
		if ((not IS_OPERATOR(input[i])) && not std::isdigit(input[i]) && not std::isspace(input[i]))
			throw (std::runtime_error("Error: Bad input -> " + getError(input, i)));
		if (std::isdigit(input[i]) && std::isdigit(input[i+1])){
			throw (std::runtime_error("Error: Expecting only values ​​less than zero."));
		}
		if (IS_OPERATOR(input[i]))
			operat++;
		if (std::isdigit(input[i]))
			operand++;
	}
	if (operand-1 != operat)
		throw (std::runtime_error("Error: Must contain 1 more operand than operators."));
}

void	RPN::normalize(std::string &input){
	for (std::size_t i = 0; i < input.length(); i++){
		if (std::isspace(input[i]))
			input.erase(i, 1);
	}
}

void	RPN::reversePolishNotation(std::string &input){
	for (std::size_t i = 0; i < input.length(); i++){
		if (std::isdigit(input[i])){
			_content.push_back(charTo<long long>(input[i]));
		}
		if (IS_OPERATOR(input[i])){
			if (_content.size() < 2)
				throw (std::runtime_error("Error: There must be operands to perform the calculation."));
			long long first = 0, last = 0;
			last = _content.back();
			_content.pop_back();
			first = _content.back();
			_content.pop_back();
			_content.push_back(calculator(input[i], first, last));
		}
	}
	std::cout << _content.back() << "\n";
}

long long	RPN::calculator(char c, long long x, long long y){
	if (c == '+')
		return ADD(x, y);
	if (c == '-')
		return SUB(x, y);
	if (c == '/')
		return DIV(x, y);
	if (c == '*')
		return MUL(x, y);
	return (0);
}

std::string RPN::getError(std::string &input, int indexError){
	std::stringstream ss;

	ss << input.substr(0, indexError);
	ss << RED << input[indexError] << RESET;
	ss << input.substr(indexError +1, input.length()- indexError);
	return ss.str();
}

RPN::RPN(){}
RPN::~RPN(){_content.clear();}
RPN::RPN(RPN const &origin){*this = origin;}
RPN&RPN::operator=(RPN const &origin){
	if (this != &origin){
		_content = origin._content;
	}
	return *this;
}
