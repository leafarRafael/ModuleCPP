/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToFloat.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:12:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 15:53:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ToFloat.hpp"

int	ToFloat::_precision = 0;

void ToFloat::convertStringToFloat(std::string input){
	float floatConvert;

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

float ToFloat::validatePseudoLiteral(std::string input){
	std::string pseudoLiteralsFloat[3] = {"-inff", "+inff", "nanf"};
	std::string pseudoLiteralsDouble[3] = {"-inf", "+inf", "nan"};
	float		value[3] = {-INFINITY, INFINITY, NAN};

	for (int i = 0; i < 3; i++){
		if (input == pseudoLiteralsFloat[i] || input == pseudoLiteralsDouble[i])
			return (value[i]);
	}
	return 0;
}

float	ToFloat::parseStringToLongDouble(std::string input){
	if (input.length() == 1)
		return handleSingleCharacterInput(static_cast<float>(input[0]));
	return converStringToDouble(input);
}

float ToFloat::converStringToDouble(std::string input){
	float				floatInput;
	char				*end;
	errno = 0;

	validateNumberFormat(input);
	floatInput = std::strtof(input.c_str(), &end);
	if (errno == ERANGE || end == input)
		throw ToFloat::ToFloatImpossible();
	return (floatInput);	
}

float ToFloat::handleSingleCharacterInput(float doubleInput){
	if (isdigit(doubleInput))
		return (doubleInput - '0');			
	return (doubleInput);
}

void	ToFloat::validateNumberFormat(std::string input){
	u_int	hasSignPrefix = 0;

	setPrecision(input);
	if (input[0] == '-' || input[0] == '+')
		hasSignPrefix = 1;
	for (u_int i = hasSignPrefix; i < input.length(); i++){
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && input[i] != 'e')
			throw ToFloat::ToFloatImpossible();
	}
}

void	ToFloat::setPrecision(std::string input){
	std::size_t			decimalPointPosition;

	decimalPointPosition = input.find(".");
	if (decimalPointPosition == std::string::npos)
		return ;
	_precision = input.length() - decimalPointPosition -1;
	if (input[input.length()-1] == 'f')
		_precision--;
}

void	ToFloat::displayConversion(float input){
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

ToFloat::ToFloat(){}
ToFloat::~ToFloat(){}
ToFloat::ToFloat(const ToFloat &ref){*this = ref;}
ToFloat&ToFloat::operator=(const ToFloat &ref){
	if (this != &ref)
		*this = ref;
	return *this;
}