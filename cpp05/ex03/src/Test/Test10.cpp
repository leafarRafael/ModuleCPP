/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test10.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:58:10 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Debug.hpp"
#include <ostream>

int	test10(){
	msgTest(" Test 10 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Methods beSigned() and signForm():\n");

	std::string name = getName();
	if (name.empty())
		name += "default";
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    AForm fo(name, 150, 150);\n");
		AForm fo(name, 150, 150);
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << fo << '\\n';\n");
		std::cout << fo << '\n';
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureaucrat burr(\"Hermes Conrad\", 1);\n");
		Bureaucrat burr("Hermes Conrad", 1);
		burr.signForm(fo);
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << burr << '\\n';\n");
		std::cout << burr << '\n';
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << fo << '\\n';\n");
		std::cout << fo << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 1;	
	}
	Debug::stop = 1;
	return (0);
}
