/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test04.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/19 15:52:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "Span.hpp"

static void	msg();

int	test04(){
	msg();
	Debug::msg(1, DECLFORMAT  "Span listSpan(50);\n");
	int		valueReturned, expected = 1538, value[] = {1000, 300,  120, 1002 , 16, 60, 55, 8, 1, 80, 1539, 25};
	Span listSpan(50);

	try{
		Debug::msg(1, DECLFORMAT  "for (int i = 0; i < 100; i++)\n");
		Debug::msg(1, DECLFORMAT  "	listSpan.addNumber(std::rand() / 1000);\n");
		for (int i = 0; i < 11; i++)
			listSpan.addNumber(value[i]);
		Debug::msg(1, DECLFORMAT  " valueReturned = listSpan.longestSpan();\n");
		valueReturned = listSpan.longestSpan();
		std::cout << "valueReturned: " <<  valueReturned << '\n';
	}catch(std::exception &e){
		std::cerr << e.what() << "\n";
		return (1);
	}
	if (valueReturned == expected)
		return 0;
	return 1;
}

static void	msg(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                                 Span class.\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                Method: longestSpan();\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD " Expecting return = 1538.\n");
}
