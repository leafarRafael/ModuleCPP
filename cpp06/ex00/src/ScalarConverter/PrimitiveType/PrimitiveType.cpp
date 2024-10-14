/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrimitiveType.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:12:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 10:36:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PrimitiveType.hpp"

void PrimitiveType::convertStringPrimitiveType(std::string input){
	long double		charConvert;

	try{
		validateEmptyInput(input);
		validatePseudoLiterals(input);
		charConvert = parseStringToLongDouble(input);
		displayConversion(charConvert);
	}catch(std::exception &e){
		std::cout << e.what();
	}
}

void	PrimitiveType::validateEmptyInput(std::string input){
	if (input.length() == 0)
		throw PrimitiveType::PrimitiveTypeImpossible();
}

void	PrimitiveType::validatePseudoLiterals(std::string input){
	std::string pseudoLiterals[6] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan"
	};
	for (int i = 0; i < 6; i++){
		if (input == pseudoLiterals[i])
			throw PrimitiveType::PrimitiveTypeImpossible();
	}
}

long	double	PrimitiveType::parseStringToLongDouble(std::string input){
	if (input.length() == 1)
		return handleSingleCharacterInput(static_cast<long double>(input[0]));
	return validateNumericString(input);
}

long double PrimitiveType::handleSingleCharacterInput(long double numericValue){
	if (!isascii(numericValue))
		throw PrimitiveType::PrimitiveTypeImpossible();
	if (isdigit(numericValue))
		throw PrimitiveType::PrimitiveTypeImpossible();			
	if (isspace(numericValue))
		throw PrimitiveType::PrimitiveTypeNonDisplayable();
	if (isprint(numericValue))
		return (numericValue);
	return (0);
}

long double PrimitiveType::validateNumericString(std::string input){
	u_int				isPositiveSign;
	std::size_t			find;

	if (input[0] == '-')
		throw PrimitiveType::PrimitiveTypeImpossible();
	validateNumberFormat(input);
	find = input.find(".");
	isPositiveSign = (input[0] == '+') ? 1 : 0;
	if (find != std::string::npos)
		return extractNumericValue(isPositiveSign, find, input);
	return extractNumericValue(isPositiveSign, input.length(), input);
}

void	PrimitiveType::validateNumberFormat(std::string input){
	u_int	isPositiveSign = 0;
	if (input[0] == '+')
		isPositiveSign = 1;
	for (u_int i = isPositiveSign; i < input.length(); i++){
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			throw PrimitiveType::PrimitiveTypeImpossible();
	}
}

long double	PrimitiveType::extractNumericValue(u_int indexSignalPositive, u_int length, std::string input){
	std::stringstream	ss;
	long double			numericValue;

	for (u_int i = indexSignalPositive; i < length; i++) {
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			throw PrimitiveType::PrimitiveTypeImpossible();
		ss << input[i];
	}
	ss >> numericValue;
	return handleSingleCharacterInput(numericValue);
}

void	PrimitiveType::displayConversion(long double input){
	if (input < 32 || input > 126)
		throw PrimitiveType::PrimitiveTypeImpossible();
	std::cout << "char: '" << static_cast<char>(input) << "'\n";
}

const char *PrimitiveType::PrimitiveTypeImpossible::what() const throw(){
	return "char: Impossible.\n";
}

const char *PrimitiveType::PrimitiveTypeNonDisplayable::what() const throw(){
	return "char: Non displayable.\n";
}
