/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test14.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:59:22 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include "RobotomyRequestForm.hpp"
#include <ostream>

int	test14(){
	msgTest(" Test 14 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Orthodox Canonical Form RobotomyRequestForm.hpp:\n");
	std::string name = getName();
	if (name.empty())
		name += "default";
	Debug::stop = 0;
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n   RobotomyRequestForm Obj1(name);\n");
		RobotomyRequestForm Obj1(name);
		Debug::msg(1, ITALI SUBLI CYAN "\n    RobotomyRequestForm Obj2(Obj1);\n");
		RobotomyRequestForm Obj2(Obj1);
		Debug::msg(1, ITALI SUBLI CYAN "\n    RobotomyRequestForm Obj3;\n");
		RobotomyRequestForm Obj3;
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
