/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test20.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/10 12:59:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

int	test20(){
	msgTest(" Test 20 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n      Methods signForm and executeForm ShrubberyCreationForm. Expectation that generates an exception \n");
	Debug::msg(1, RED ITALI SUBLI BOLD "   Unsigned form:\n");

	std::string name = getName();
	if (name.empty())
		name += "default";

	Debug::msg(1, ITALI SUBLI CYAN "\n  AForm *objForm = new ShrubberyCreationForm(name);\n");
	AForm *objForm = new ShrubberyCreationForm(name);
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n   std::cout << *objForm;\n");
		std::cout << *objForm;

		Debug::msg(1, ITALI SUBLI CYAN "\n   Bureaucrat objBureaucrat(\"Hermes Conrad\", 1);\n");
		Bureaucrat objBureaucrat(name.append(" Bureaucrat"), 1);
		
		Debug::msg(1, ITALI SUBLI CYAN "\n   std::cout << objBureaucrat << '\\n';\n");
		std::cout << objBureaucrat << '\n';
	
		Debug::msg(1, ITALI SUBLI CYAN "\n   objBureaucrat.executeForm(*objForm);\n");
		objBureaucrat.executeForm(*objForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		delete objForm;
		return 0;	
	}
	delete objForm;
	Debug::stop = 1;
	return (1);
}
