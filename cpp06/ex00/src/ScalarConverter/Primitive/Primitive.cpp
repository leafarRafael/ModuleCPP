/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Primitive.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:12:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 12:24:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Primitive.hpp"

void Primitive::convertStringPrimitive(std::string input){
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

void	Primitive::validateEmptyInput(std::string input){
	if (input.length() == 0)
		throw Primitive::PrimitiveImpossible();
}

void	Primitive::validatePseudoLiterals(std::string input){
	std::string pseudoLiterals[6] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan"
	};
	for (int i = 0; i < 6; i++){
		if (input == pseudoLiterals[i])
			throw Primitive::PrimitiveImpossible();
	}
}

long	double	Primitive::parseStringToLongDouble(std::string input){
	if (input.length() == 1)
		return handleSingleCharacterInput(static_cast<long double>(input[0]));
	return validateNumericString(input);
}

long double Primitive::handleSingleCharacterInput(long double numericValue){
	if (!isascii(numericValue))
		throw Primitive::PrimitiveImpossible();
	if (isdigit(numericValue))
		throw Primitive::PrimitiveImpossible();			
	if (isspace(numericValue))
		throw Primitive::PrimitiveNonDisplayable();
	if (isprint(numericValue))
		return (numericValue);
	return (0);
}

long double Primitive::validateNumericString(std::string input){
	u_int				isPositiveSign;
	std::size_t			find;

	if (input[0] == '-')
		throw Primitive::PrimitiveImpossible();
	validateNumberFormat(input);
	find = input.find(".");
	isPositiveSign = (input[0] == '+') ? 1 : 0;
	if (find != std::string::npos)
		return extractNumericValue(isPositiveSign, find, input);
	return extractNumericValue(isPositiveSign, input.length(), input);
}

void	Primitive::validateNumberFormat(std::string input){
	u_int	isPositiveSign = 0;
	if (input[0] == '+')
		isPositiveSign = 1;
	for (u_int i = isPositiveSign; i < input.length(); i++){
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			throw Primitive::PrimitiveImpossible();
	}
}

long double	Primitive::extractNumericValue(u_int indexSignalPositive, u_int length, std::string input){
	std::stringstream	ss;
	long double			numericValue;

	for (u_int i = indexSignalPositive; i < length; i++) {
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			throw Primitive::PrimitiveImpossible();
		ss << input[i];
	}
	ss >> numericValue;
	return handleSingleCharacterInput(numericValue);
}

void	Primitive::displayConversion(long double input){
	if (input < 32 || input > 126)
		throw Primitive::PrimitiveImpossible();
	std::cout << "char: '" << static_cast<char>(input) << "'\n";
}

const char *Primitive::PrimitiveImpossible::what() const throw(){
	return "char: Impossible.\n";
}

const char *Primitive::PrimitiveNonDisplayable::what() const throw(){
	return "char: Non displayable.\n";
}
