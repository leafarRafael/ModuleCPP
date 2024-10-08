/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test26.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 10:48:02 by rbutzke          ###   ########.fr       */
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

	Debug::msg(1, ITALI SUBLI CYAN "\n  AForm *objForm = new PresidentialPardonForm(\"Ona\");\n");
	AForm *objForm = new PresidentialPardonForm("Ona");
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n   std::cout << *objForm;\n");
		std::cout << *objForm;

		Debug::msg(1, ITALI SUBLI CYAN "\n   Bureaucrat objBureaucrat(\"Hermes Conrad\", 1);\n");
		Bureaucrat objBureaucrat("Hermes Conrad", 1);
		
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
