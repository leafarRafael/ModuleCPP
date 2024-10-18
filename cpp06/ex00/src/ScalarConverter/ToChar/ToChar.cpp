/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToChar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:12:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/18 13:40:34 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ToChar.hpp"

void ToChar::convertStringToChar(std::string input){
	int	convert;

	try{
		validateEmptyInput(input);
		validatePseudoLiterals(input);
		convert = parseStringToLongDouble(input);
		displayConversion(convert);
	}catch(std::exception &e){
		std::cout << e.what();
	}
}

void	ToChar::validateEmptyInput(std::string input){
	if (input.length() == 0)
		throw ToChar::ToCharImpossible();
}

void	ToChar::validatePseudoLiterals(std::string input){
	std::string pseudoLiterals[6] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan"
	};
	for (int i = 0; i < 6; i++){
		if (input == pseudoLiterals[i])
			throw ToChar::ToCharImpossible();
	}
}

int	ToChar::parseStringToLongDouble(std::string input){
	if (input.length() == 1)
		return handleSingleCharacterInput(static_cast<int>(input[0]));
	return converStringToDouble(input);
}

int ToChar::converStringToDouble(std::string input){
	int					numericValue;

	if (input[0] == '-')
		throw ToChar::ToCharImpossible();
	validateNumberFormat(input);
	errno = 0;
	numericValue = std::atoi(input.c_str());
	if (errno == ERANGE)
		throw ToChar::ToCharImpossible();
	return handleSingleCharacterInput(numericValue);;
}

int ToChar::handleSingleCharacterInput(int numericValue){
	if (!isascii(numericValue))
		throw ToChar::ToCharImpossible();
	if (isdigit(numericValue))
		throw ToChar::ToCharImpossible();
	if (isspace(numericValue))
		throw ToChar::ToCharNonDisplayable();
	if (isprint(numericValue))
		return (numericValue);
	return (0);
}

void	ToChar::validateNumberFormat(std::string input){
	u_int	isPositiveSign = 0;

	if (input[0] == '+')
		isPositiveSign = 1;
	for (u_int i = isPositiveSign; i < input.length(); i++){
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			throw ToChar::ToCharImpossible();
	}
}

void	ToChar::displayConversion(int input){
	if (input < 32 || input > 126)
		throw ToChar::ToCharImpossible();
	std::cout << "char: '" << static_cast<char>(input) << "'\n";
}

const char *ToChar::ToCharImpossible::what() const throw(){
	return "char: Impossible.\n";
}

const char *ToChar::ToCharNonDisplayable::what() const throw(){
	return "char: Non displayable.\n";
}

ToChar::ToChar(){}
ToChar::~ToChar(){}
ToChar::ToChar(const ToChar &ref){*this = ref;}
ToChar&ToChar::operator=(const ToChar &ref){
	if (this != &ref)
		*this = ref;
	return *this;
}
