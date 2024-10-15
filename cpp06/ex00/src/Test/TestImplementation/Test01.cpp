/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 16:06:53 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Debug.hpp"
#include <iomanip>
#include <iostream>
#include "UnitTest.hpp"

int	test01(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                   ScalarConvert   :\n");
	Debug::msg(1, MAGENTA ITALI SUBLI BOLD "      Negative value:\n");
	Debug::stop = 0;
	std::string test[5] = {"-42", "-1.9999", "-42.00f", "-42.1111", "-42.999f"};

	for(int i = 0; i < 5; i++){
		std::cout << RED ITALI SUBLI BOLD "           Input: " RESET << test[i] << "\n" ;
		ScalarConverter::convert(test[i]);
		std::cout << "\n\n";
	}
	Debug::stop = 1;
	return (0);
}
