/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test07.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/19 16:32:50 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "Span.hpp"

static void	msg();

int	test07(){
	msg();
	Debug::msg(1, DECLFORMAT  "Span listSpan(60);\n");
	Debug::msg(1, DECLFORMAT  "Span listSpan2(60);\n");
	Span listSpan(60);
	Span listSpan2(60);

	try{
		Debug::msg(1, DECLFORMAT  "listSpan.fillSpan(30, 80);\n");
		Debug::msg(1, DECLFORMAT  "listSpan2.fillSpan(80, 30);\n");
		listSpan.fillSpan(30, 80);
		listSpan2.fillSpan(80, 30);
	}catch(std::exception &e){
		std::cerr << e.what() << "\n";
		return (1);
	}
	return 0;
}

static void	msg(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                                     Span class.\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "                           Method: fillSpan();\n");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD " Expecting retorn ok.\n\n");
}
