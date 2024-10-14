/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 12:24:40 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Debug.hpp"
#include "Color.hpp"
#include "ToChar.hpp"
#include "ToInt.hpp"
#include "ToFloat.hpp"
#include "ToDouble.hpp"

void ScalarConverter::convert(std::string input){
	ToChar::convertStringToChar(input);
	ToInt::convertStringToInt(input);
	ToFloat::convertStringToFloat(input);
	ToDouble::convertStringToDouble(input);
}

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &ref){*this = ref;}
ScalarConverter&ScalarConverter::operator=(const ScalarConverter &ref){
	if (this != &ref)
		*this = ref;
	return *this;
}
