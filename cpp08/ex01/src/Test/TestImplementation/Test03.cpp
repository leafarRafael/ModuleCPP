/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test03.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/19 15:52:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "Span.hpp"

static void	msg();

int	test03(){
	msg();
	Debug::msg(1, DECLFORMAT  "Span listSpan(50);\n");
	int		valueReturned, value[] = {1000, 300,  120, 1002 , 16, 60, 55, 8, 1, 80, 1500, 25};
	Span listSpan(50);

	try{
		Debug::msg(1, DECLFORMAT  "for (int i = 0; i < 100; i++)\n");
		Debug::msg(1, DECLFORMAT  "	listSpan.addNumber(std::rand() / 1000);\n");
		for (int i = 0; i < 11; i++)
			listSpan.addNumber(value[i]);
		Debug::msg(1, DECLFORMAT  "	valueReturned = listSpan.shortestSpan();\n");
		valueReturned = listSpan.shortestSpan();
		std::cout << "valueReturned: " <<  valueReturned << '\n';
	}catch(std::exception &e){
		std::cerr << e.what() << "\n";
		return (1);
	}
	if (valueReturned == 2)
		return 0;
	return 1;
}

static void	msg(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                                 Span class.\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                Method: shortestSpan();\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD " Expecting return = 2\n");
}