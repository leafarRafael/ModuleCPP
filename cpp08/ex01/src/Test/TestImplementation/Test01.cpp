/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/19 15:57:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

static void	msg();
int	test01(){
	msg();
	Debug::msg(1, DECLFORMAT  "Span listSpan(50);\n");
	Span listSpan(50);
	std::srand(std::time(0));
	try{
		Debug::msg(1, DECLFORMAT  "listSpan.addNumber(std::rand() / 1000);\n");
		listSpan.addNumber(std::rand() % 10);
		Debug::msg(1, DECLFORMAT  "int i = listSpan.shortestSpan();\n");
		int i = listSpan.shortestSpan();
		(void)i;
	}catch(std::exception &e){
		std::cerr << e.what() << "\n";
		return (0);
	}
	return 1;
}

static void	msg(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                                Span class.\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "               Method: shortestSpan();\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "           List size <= 1.\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD " Expecting exception.\n");
}