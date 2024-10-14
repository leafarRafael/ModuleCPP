/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToDouble.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:12:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 13:06:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ToDouble.hpp"

int	ToDouble::_precision = 0;

void ToDouble::convertStringToDouble(std::string input){
	long double doubleConvert;

	try{
		validateEmptyInput(input);
		doubleConvert = validatePseudoLiteral(input);
		if (!doubleConvert)
			doubleConvert = parseStringToLongDouble(input);
		displayConversion(doubleConvert);
	}catch(std::exception &e){
		std::cout << e.what();
	}
}

void	ToDouble::validateEmptyInput(std::string input){
	if (input.length() == 0)
		throw ToDouble::ToDoubleImpossible();
}

long double ToDouble::validatePseudoLiteral(std::string input){
	std::string pseudoLiteralsFloat[3] = {"-inff", "+inff", "nanf"};
	std::string pseudoLiteralsDouble[3] = {"-inf", "+inf", "nan"};
	float		value[3] = {-INFINITY, INFINITY, NAN};

	for (int i = 0; i < 3; i++){
		if (input == pseudoLiteralsFloat[i] || input == pseudoLiteralsDouble[i])
			return (value[i]);
	}
	return 0;
}

long double ToDouble::handleSingleCharacterInput(long double doubleInput){
	if (isdigit(doubleInput))
		return (doubleInput - '0');			
	return (doubleInput);
}

long	double	ToDouble::parseStringToLongDouble(std::string input){
	if (input.length() == 1)
		return handleSingleCharacterInput(static_cast<long double>(input[0]));
	return validateNumericString(input);
}

long double ToDouble::validateNumericString(std::string input){
	u_int				hasSignPrefix;
	std::size_t			decimalPointPosition;

	validateNumberFormat(input);
	decimalPointPosition = input.find(".");
	hasSignPrefix = (input[0] == '-' || input[0] == '+') ? 1 : 0;
	if (decimalPointPosition != std::string::npos)
		return extractNumericValue(hasSignPrefix, decimalPointPosition, input);
	return extractNumericValue(hasSignPrefix, input.length(), input);
}


long double	ToDouble::extractNumericValue(u_int hasSignPrefix, u_int length, std::string input){
	std::stringstream	ss, sss(input);
	long double			doubleInput;
	
	for (u_int i = hasSignPrefix; i < length; i++) {
		if (!isdigit(input[i]))
			throw ToDouble::ToDoubleImpossible();
		ss << input[i];
	}
	sss >> doubleInput;
	return (doubleInput = (input[0] == '-') ? (doubleInput *-1) : doubleInput);	
}

void	ToDouble::validateNumberFormat(std::string input){
	u_int	hasSignPrefix = 0;

	setPrecision(input);
	if (input[0] == '-' || input[0] == '+')
		hasSignPrefix = 1;
	for (u_int i = hasSignPrefix; i < input.length(); i++){
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			throw ToDouble::ToDoubleImpossible();
	}
}

void	ToDouble::setPrecision(std::string input){
	std::size_t			decimalPointPosition;

	decimalPointPosition = input.find(".");
	if (decimalPointPosition == std::string::npos)
		return ;
	_precision = input.length() - decimalPointPosition -1;
	if (input[input.length()-1] == 'f')
		_precision--;
}

void	ToDouble::displayConversion(long double input){
	_precision == 0 ? _precision++ : _precision;
	std::cout << std::fixed << std::setprecision(_precision)
		<< "Double: " << static_cast<double>(input) << '\n';
	_precision = 0;
}

const char *ToDouble::ToDoubleImpossible::what() const throw(){
	return "Double: Impossible.\n";
}

const char *ToDouble::ToDoubleNonDisplayable::what() const throw(){
	return "Double: Non displayable.\n";
}
