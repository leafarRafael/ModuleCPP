/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test05.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/19 16:06:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "Span.hpp"

static void	msg();

int	test05(){
	msg();
	Debug::msg(1, DECLFORMAT  "Span listSpan(10);\n");
	Span listSpan(10);

	try{
		Debug::msg(1, DECLFORMAT  "listSpan.fillSpan(50);\n");
		listSpan.fillSpan(50);
	}catch(std::exception &e){
		std::cerr << e.what() << "\n";
		return (0);
	}
	return 1;
}

static void	msg(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                                     Span class.\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                           Method: fillSpan();\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "  number of elements greater than capacity;\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD " Expecting exception.\n\n");
}
