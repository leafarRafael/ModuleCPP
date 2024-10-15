/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToInt.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:12:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 15:45:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ToInt.hpp"

void ToInt::convertStringToInt(std::string input){
	long	convert;

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

long	ToInt::parseStringToLongDouble(std::string input){
	if (input.length() == 1)
		return handleSingleCharacterInput(static_cast<long>(input[0]));
	return converStringToDouble(input);
}

long ToInt::converStringToDouble(std::string input){
	long 				intInput;
	validateNumberFormat(input);

	errno = 0;
	intInput = std::atol(input.c_str());
	if (errno == ERANGE)
		throw ToInt::ToIntImpossible();
	return checkRange(intInput);
}

long ToInt::handleSingleCharacterInput(long doubleInput){
	if (isdigit(doubleInput))
		return (doubleInput - '0');			
	return (doubleInput);
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

long ToInt::checkRange(long doubleInput){
	if (doubleInput < std::numeric_limits<int>::min())		
		throw ToInt::ToIntNonDisplayable();
	if (doubleInput > std::numeric_limits<int>::max())		
		throw ToInt::ToIntNonDisplayable();
	return (doubleInput);
}


void	ToInt::displayConversion(long input){
	std::cout << "Int: " << static_cast<int>(input) << '\n';
}

const char *ToInt::ToIntImpossible::what() const throw(){
	return "Int: Impossible.\n";
}

const char *ToInt::ToIntNonDisplayable::what() const throw(){
	return "Int: Non displayable.\n";
}

ToInt::ToInt(){}
ToInt::~ToInt(){}
ToInt::ToInt(const ToInt &ref){*this = ref;}
ToInt&ToInt::operator=(const ToInt &ref){
	if (this != &ref)
		*this = ref;
	return *this;
}