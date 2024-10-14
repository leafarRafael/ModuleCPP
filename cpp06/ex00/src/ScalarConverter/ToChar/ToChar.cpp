/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToChar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:12:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 10:40:11 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ToChar.hpp"

void ToChar::convertStringToChar(std::string input){
	long double	convert;

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

long	double	ToChar::parseStringToLongDouble(std::string input){
	if (input.length() == 1)
		return handleSingleCharacterInput(static_cast<long double>(input[0]));
	return validateNumericString(input);
}

long double ToChar::handleSingleCharacterInput(long double numericValue){
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

long double ToChar::validateNumericString(std::string input){
	u_int				isPositiveSign;
	std::size_t			find;

	if (input[0] == '-')
		throw ToChar::ToCharImpossible();
	validateNumberFormat(input);
	find = input.find(".");
	isPositiveSign = (input[0] == '+') ? 1 : 0;
	if (find != std::string::npos)
		return extractNumericValue(isPositiveSign, find, input);
	return extractNumericValue(isPositiveSign, input.length(), input);
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

long double	ToChar::extractNumericValue(u_int indexSignalPositive, u_int length, std::string input){
	std::stringstream	ss;
	long double			numericValue;

	for (u_int i = indexSignalPositive; i < length; i++) {
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			throw ToChar::ToCharImpossible();
		ss << input[i];
	}
	ss >> numericValue;
	return handleSingleCharacterInput(numericValue);
}

void	ToChar::displayConversion(long double input){
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
