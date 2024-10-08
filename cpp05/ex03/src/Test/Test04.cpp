/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test04.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:55:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Bureaucrat.hpp"
#include "Debug.hpp"

int	test04(){
	msgTest(" Test 04 ");
	
	std::string name = getName();
	if (name.empty())
		name += "default";
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Iterator member function. Tests iterate until exception is generated:\n");
	Debug::msg(1, ITALI SUBLI CYAN "\n    Bureaucrat A(name, 150);\n");
	Bureaucrat A(name, 150);
	try{
		Debug::msg(1, CYAN "\n    for (;;)\n	A.incrementGrade();\n");
		for (;;)
			A.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		std::cout << A << '\n';
		return 0;	
	}
	return (1);
}
