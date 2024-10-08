/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test15.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 15:00:03 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

int	test15(){
	msgTest(" Test 15 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n      Methods sifnForm and executeForm RobotomyRequestForm. Expectation that does NOT generate an exception \n");
	std::string name = getName();
	if (name.empty())
		name += "default";
	Debug::msg(1, ITALI SUBLI CYAN "\n  AForm *objForm = new RobotomyRequestForm(name);\n");
	AForm *objForm = new RobotomyRequestForm(name);
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n   std::cout << *objForm;\n");
		std::cout << *objForm;

		Debug::msg(1, ITALI SUBLI CYAN "\n   Bureaucrat objBureaucrat(name, 1);\n");
		Bureaucrat objBureaucrat(name.append(" 2"), 1);
		
		Debug::msg(1, ITALI SUBLI CYAN "\n   std::cout << objBureaucrat << '\\n';\n");
		std::cout << objBureaucrat << '\n';

		Debug::msg(1, ITALI SUBLI CYAN "\n   objBureaucrat.signForm(*objForm);\n");
		objBureaucrat.signForm(*objForm);
		Debug::msg(1, ITALI SUBLI CYAN "\n   objBureaucrat.executeForm(*objForm);\n");
		objBureaucrat.executeForm(*objForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		delete objForm;
		return 1;	
	}
	delete objForm;
	Debug::stop = 1;
	return (0);
}
