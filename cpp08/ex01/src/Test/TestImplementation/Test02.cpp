/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test02.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/19 15:51:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include <cstdlib>
#include "Span.hpp"
#include <ctime>

static void	msg();

int	test02(){
	msg();
	Debug::msg(1, DECLFORMAT  "Span listSpan(50);\n");
	Span listSpan(50);
	std::srand(std::time(0));
	try{
		Debug::msg(1, DECLFORMAT  "	listSpan.addNumber(std::rand() / 1000);\n");
		listSpan.addNumber(std::rand() / 1000);
		Debug::msg(1, DECLFORMAT  "int i = listSpan.longestSpan();\n");
		int i = listSpan.longestSpan();
		(void)i;
	}catch(std::exception &e){
		std::cerr << e.what() << "\n";
		return (0);
	}
	return 1;
}

static void	msg(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                                Span class.\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "               Method: longestSpan();\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "            List size <= 1\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD " Expecting exception.\n");
}