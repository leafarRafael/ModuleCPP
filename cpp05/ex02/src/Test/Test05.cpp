/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test05.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/07 09:08:06 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Bureaucrat.hpp"
#include "Debug.hpp"

int	test05(){
	msgTest(" Test 05 ");

	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n  Decrementing member function. Tests decrements until exception is generated:\n");
	Debug::msg(1, ITALI SUBLI CYAN "\n    Bureaucrat A(\"Hermes Conrad A\", 1);\n");
	Bureaucrat A("Hermes Conrad A", 1);
	try{
		Debug::msg(1, CYAN "\n    for (;;)\n	A.decrementGrade();\n");
		for (;;)
			A.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		std::cout << A << '\n';
		return 0;	
	}
	return (1);
}
