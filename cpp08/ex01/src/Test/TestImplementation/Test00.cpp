/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/19 15:42:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "Span.hpp"
#include <cstdlib>
#include <ctime>

static void	msg();

int	test00(){
	msg();
	Debug::msg(1, DECLFORMAT  "Span listSpan(50);\n");
	std::srand(std::time(0));
	Span	listSpan(50);
	try{
		Debug::msg(1, DECLFORMAT  "for (int i = 0; i < 100; i++)\n");
		Debug::msg(1, DECLFORMAT  "	listSpan.addNumber(std::rand() / 1000);\n");
		for (int i = 0; i < 100; i++)
			listSpan.addNumber(std::rand() / 1000);
	}catch(std::exception &e){
		std::cerr << e.what() << "\n";
		return (0);
	}
	return 1;
}

static void	msg(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                                        Span class.\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                    Method: addNumber();\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD " Number of elements greater than 'N'.\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD " Expecting exception.\n");
}