/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToInt.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:12:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 10:44:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ToInt.hpp"

void ToInt::convertStringToInt(std::string input){
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

void	ToInt::validateEmptyInput(std::string input){
	if (input.length() == 0)
		throw ToInt::ToIntImpossible();
}

void	ToInt::validatePseudoLiterals(std::string input){
	std::string pseudoLiterals[6] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan"
	};
	for (int i = 0; i < 6; i++){
		if (input == pseudoLiterals[i])
			throw ToInt::ToIntImpossible();
	}
}

long double ToInt::handleSingleCharacterInput(long double doubleInput){
	if (isdigit(doubleInput))
		return (doubleInput - '0');			
	return (doubleInput);
}

long	double	ToInt::parseStringToLongDouble(std::string input){
	if (input.length() == 1)
		return handleSingleCharacterInput(static_cast<long double>(input[0]));
	return validateNumericString(input);
}

long double ToInt::checkRange(long double doubleInput){
	if (doubleInput < std::numeric_limits<int>::min())		
		throw ToInt::ToIntNonDisplayable();
	if (doubleInput > std::numeric_limits<int>::max())		
		throw ToInt::ToIntNonDisplayable();
	return (doubleInput);
}

long double ToInt::validateNumericString(std::string input){
	u_int				hasSignPrefix;
	std::size_t			decimalPointPosition;

	validateNumberFormat(input);
	decimalPointPosition = input.find(".");
	hasSignPrefix = (input[0] == '-' || input[0] == '+') ? 1 : 0;
	if (decimalPointPosition != std::string::npos)
		return extractNumericValue(hasSignPrefix, decimalPointPosition, input);
	return extractNumericValue(hasSignPrefix, input.length(), input);
}

long double	ToInt::extractNumericValue(u_int indexSignalPositive, u_int length, std::string input){
	std::stringstream	ss;
	long double			doubleInput;
	
	for (u_int i = indexSignalPositive; i < length; i++) {
		if (!isdigit(input[i]))
			throw ToInt::ToIntImpossible();
		ss << input[i];
	}
	ss >> doubleInput;
	return checkRange(doubleInput = (input[0] == '-') ? (doubleInput *-1) : doubleInput);	
}

void	ToInt::validateNumberFormat(std::string input){
	u_int	hasSignPrefix = 0;

	if (input[0] == '-' || input[0] == '+')
		hasSignPrefix = 1;
	for (u_int i = hasSignPrefix; i < input.length(); i++){
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			throw ToInt::ToIntImpossible();
	}
}

void	ToInt::displayConversion(long double input){
	std::cout << "Int: " << static_cast<int>(input) << '\n';
}

const char *ToInt::ToIntImpossible::what() const throw(){
	return "Int: Impossible.\n";
}

const char *ToInt::ToIntNonDisplayable::what() const throw(){
	return "Int: Non displayable.\n";
}
