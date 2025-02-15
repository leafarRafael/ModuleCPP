/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 16:06:40 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Debug.hpp"
#include <iomanip>
#include <iostream>
#include "UnitTest.hpp"

int	test00(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                   ScalarConvert   :\n");
	Debug::msg(1, MAGENTA ITALI SUBLI BOLD "      Pseudo Literal:\n");
	Debug::stop = 0;
	std::string test[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan",};

	for(int i = 0; i < 6; i++){
		std::cout << RED ITALI SUBLI BOLD "           Input: " RESET << test[i] << "\n" ;
		ScalarConverter::convert(test[i]);
		std::cout << "\n";
	}
	Debug::stop = 1;
	return (0);
}
