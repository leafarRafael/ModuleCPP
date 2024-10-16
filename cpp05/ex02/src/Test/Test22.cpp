/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test22.cpp                                         :+:      :+:    :+:   */
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

int	test22(){
	msgTest(" Test 22 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n      Methods signForm and executeForm ShrubberyCreationForm. Expectation that generates an exception \n");
	Debug::msg(1, RED ITALI SUBLI BOLD "   Low grade of bureaucrat to execute\n");

	Debug::msg(1, ITALI SUBLI CYAN "\n  AForm *objForm = new ShrubberyCreationForm(\"Osson\");\n");
	AForm *objForm = new ShrubberyCreationForm("Osson");
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n   std::cout << *objForm;\n");
		std::cout << *objForm;

		Debug::msg(1, ITALI SUBLI CYAN "\n   Bureaucrat objBureaucrat(\"Hermes Conrad\", 72);\n");
		Bureaucrat objBureaucrat("Hermes Conrad", 72);
		Debug::msg(1, ITALI SUBLI CYAN "\n   std::cout << objBureaucrat << '\\n';\n");
		std::cout << objBureaucrat << '\n';

		Debug::msg(1, ITALI SUBLI CYAN "\n   Bureaucrat objBurr(\"Ynos\", 150);\n");
		Bureaucrat objBurr("Ynos", 150);
		Debug::msg(1, ITALI SUBLI CYAN "\n   std::cout << objBurr << '\\n';\n");
		std::cout << objBurr << '\n';

		
		Debug::msg(1, ITALI SUBLI CYAN "\n   objBureaucrat.signForm(*objForm);\n");
		objBureaucrat.signForm(*objForm);

		Debug::msg(1, ITALI SUBLI CYAN "\n   objBurr2.executeForm(*objForm);\n");
		objBurr.executeForm(*objForm);
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
