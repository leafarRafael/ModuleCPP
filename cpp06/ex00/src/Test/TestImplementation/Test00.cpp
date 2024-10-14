/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 09:56:39 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Debug.hpp"
#include <iomanip>
#include <iostream>

std::string	getInputTest();

int	test00(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   ScalarConvert   :\n");
	Debug::stop = 0;
	std::string test[18] = {
		"-inff", "+inff",
		"nanf", "-inf",
		"+inf", "nan",
		"0", "-1",
		"c", "10.16f", 
		"abcsde", "42",
		"-42", "+66.0001",
		"-66", "42.111",
		"10.000000f", "10.000"
	};
	
	for(int i = 0; i < 18; i++){
		std::cout << RED "Input: " RESET << test[i] << "\n" ;
		ScalarConverter::convert(test[i]);
		std::cout << "\n\n";
	}

	Debug::stop = 1;
	return (0);
}

std::string	getInputTest(){
	std::string		input;
	std::getline(std::cin, input);
	return input;
}