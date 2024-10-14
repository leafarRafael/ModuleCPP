/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToFloat.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:12:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 10:09:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ToFloat.hpp"

int	ToFloat::_precision = 0;

void ToFloat::convertStringToFloat(std::string input){
	long double floatConvert;

	try{
		validateEmptyInput(input);
		floatConvert = validatePseudoLiteral(input);
		if (!floatConvert)
			floatConvert = parseStringToLongDouble(input);
		displayConversion(floatConvert);
	}catch(std::exception &e){
		std::cout << e.what();
	}
}

void	ToFloat::validateEmptyInput(std::string input){
	if (input.length() == 0)
		throw ToFloat::ToFloatImpossible();
}

long double ToFloat::validatePseudoLiteral(std::string input){
	std::string pseudoLiteralsFloat[3] = {"-inff", "+inff", "nanf"};
	std::string pseudoLiteralsDouble[3] = {"-inf", "+inf", "nan"};
	float		value[3] = {-INFINITY, INFINITY, NAN};

	for (int i = 0; i < 3; i++){
		if (input == pseudoLiteralsFloat[i] || input == pseudoLiteralsDouble[i])
			return (value[i]);
	}
	return 0;
}

long double ToFloat::handleSingleCharacterInput(long double doubleInput){
	if (isdigit(doubleInput))
		return (doubleInput - '0');			
	return (doubleInput);
}

long	double	ToFloat::parseStringToLongDouble(std::string input){
	if (input.length() == 1)
		return handleSingleCharacterInput(static_cast<long double>(input[0]));
	return validateNumericString(input);
}

long double ToFloat::validateNumericString(std::string input){
	u_int				hasSignPrefix;
	std::size_t			decimalPointPosition;

	validateNumberFormat(input);
	decimalPointPosition = input.find(".");
	hasSignPrefix = (input[0] == '-' || input[0] == '+') ? 1 : 0;
	if (decimalPointPosition != std::string::npos)
		return extractNumericValue(hasSignPrefix, decimalPointPosition, input);
	return extractNumericValue(hasSignPrefix, input.length(), input);
}


long double	ToFloat::extractNumericValue(u_int hasSignPrefix, u_int length, std::string input){
	std::stringstream	ss, sss(input);
	long double			doubleInput;
	
	for (u_int i = hasSignPrefix; i < length; i++) {
		if (!isdigit(input[i]))
			throw ToFloat::ToFloatImpossible();
		ss << input[i];
	}
	sss >> doubleInput;
	return (doubleInput = (input[0] == '-') ? (doubleInput *-1) : doubleInput);	
}

void	ToFloat::validateNumberFormat(std::string input){
	u_int	hasSignPrefix = 0;

	setPrecision(input);

	if (input[0] == '-' || input[0] == '+')
		hasSignPrefix = 1;
	for (u_int i = hasSignPrefix; i < input.length(); i++){
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			throw ToFloat::ToFloatImpossible();
	}
}

void	ToFloat::setPrecision(std::string input){
	std::size_t			decimalPointPosition;

	decimalPointPosition = input.find(".");
	if (decimalPointPosition == std::string::npos)
		return ;
	for (u_int i = decimalPointPosition+1; i < input.length(); i++){
		if (input[i] == 'f')
			break ;
		_precision++;
	}
}

void	ToFloat::displayConversion(long double input){
	std::string newLine("f\n");
	_precision == 0 ? _precision++ : _precision;
	std::cout << std::fixed << std::setprecision(_precision)
			<< "Float: " << static_cast<float>(input) << newLine;
	_precision = 0;
}

const char *ToFloat::ToFloatImpossible::what() const throw(){
	return "Float: Impossible.\n";
}

const char *ToFloat::ToFloatNonDisplayable::what() const throw(){
	return "Float: Non displayable.\n";
}
