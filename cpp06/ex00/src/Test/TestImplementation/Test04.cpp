/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test04.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 16:25:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Debug.hpp"
#include <iomanip>
#include <iostream>
#include "UnitTest.hpp"

int	test04(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                   ScalarConvert   :\n");
	Debug::msg(1, MAGENTA ITALI SUBLI BOLD "       getInput user:\n");
	Debug::stop = 0;

	for(;;){
		std::cout <<  RED ITALI SUBLI BOLD "   Enter a value for conversion (or 'exit'): " RESET;
		std::string input = getInputTest();
		std::cout << ITALI SUBLI BOLD "                            \n" RESET;
		if (input == "exit")
			break ;
		std::cout << "\n";
		ScalarConverter::convert(input);
		
	}
	Debug::stop = 1;
	return (0);
}
