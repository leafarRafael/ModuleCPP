/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test12.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 08:52:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

int	test12(){
	msgTest(" Test 12 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Orthodox Canonical Form ShrubberyCreationForm.hpp:\n");

	Debug::stop = 0;
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n   ShrubberyCreationForm Obj1(\"Obj_Shruberry\");\n");
		ShrubberyCreationForm Obj1("Obj_Shruberry");
		Debug::msg(1, ITALI SUBLI CYAN "\n    ShrubberyCreationForm Obj2(Obj1);\n");
		ShrubberyCreationForm Obj2(Obj1);
		Debug::msg(1, ITALI SUBLI CYAN "\n    ShrubberyCreationForm Obj3;\n");
		ShrubberyCreationForm Obj3;
		Debug::msg(1, ITALI SUBLI CYAN "\n    Obj3 = Obj1;\n");
		Obj3 = Obj1;
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << A;\n");
		std::cout << Obj1 << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 1;	
	}
	Debug::stop = 1;
	return (0);
}
