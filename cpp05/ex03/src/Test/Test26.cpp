/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test26.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 15:12:11 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

int	test26(){
	msgTest(" Test 26 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n      Methods sifnForm and executeForm PresidentialPardonForm. Expectation that does NOT generate an exception \n");

	std::string name = getName();
	if (name.empty())
		name += "default";

	Debug::msg(1, ITALI SUBLI CYAN "\n  AForm *objForm = new PresidentialPardonForm(name);\n");
	AForm *objForm = new PresidentialPardonForm(name);
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n   std::cout << *objForm;\n");
		std::cout << *objForm;

		Debug::msg(1, ITALI SUBLI CYAN "\n   Bureaucrat objBureaucrat(name.append(\" Bureaucrat\"), 1);\n");
		Bureaucrat objBureaucrat(name.append(" Bureaucrat"), 1);
		
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
