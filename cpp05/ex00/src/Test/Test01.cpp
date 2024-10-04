/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/04 17:29:06 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Bureaucrat.hpp"
#include "Debug.hpp"

int	test01(){
	msgTest(" Test 01 ");

	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Grid Value Margins:\n");
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureucrat A(\"Hermes Conrad A\", 1);\n");
		Bureucrat A("Hermes Conrad A", 1);
		std::cout << A << '\n';
	
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureucrat B(\"Hermes Conrad B\", 150);\n");
		Bureucrat B("Hermes Conrad B", 150);
		std::cout << B << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 1;	
	}
	return (0);
}
