/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/18 17:24:32 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "Span.hpp"

int	test00(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                         iter ptr Function toupper:\n");
	Debug::msg(1, GREEN ITALI SUBLI BOLD "   expectation that changes the statement.\n");

	Span listSpan(50);

	try{
		for (int i = 0; i < 100; i++){
			listSpan.addNumber(i);
			std::cout << '[' << i << "] ";
		}
	}catch(std::exception &e){
		std::cerr << e.what() << "\n";
	}
	std::cout << "\nshortSpan:  " << listSpan.shortestSpan(4, 10) << "\n";

	return 0;
}

