/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test24.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 10:47:45 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

int	test24(){
	msgTest(" Test 24 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n      Methods sifnForm and executeForm PresidentialPardonForm. Expectation that generates an exception \n");
	Debug::msg(1, RED ITALI SUBLI BOLD "   Low grade of bureaucrat to sign:\n");

	Debug::msg(1, ITALI SUBLI CYAN "\n  AForm *objForm = new PresidentialPardonForm(\"Ona\");\n");
	AForm *objForm = new PresidentialPardonForm("Ona");
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n   std::cout << *objForm;\n");
		std::cout << *objForm;

		Debug::msg(1, ITALI SUBLI CYAN "\n   Bureaucrat objBureaucrat(\"Hermes Conrad\", 150);\n");
		Bureaucrat objBureaucrat("Hermes Conrad", 150);

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
		return 0;	
	}
	delete objForm;
	Debug::stop = 1;
	return (1);
}
