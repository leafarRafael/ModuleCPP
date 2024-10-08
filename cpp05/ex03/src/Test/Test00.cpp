/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:52:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Bureaucrat.hpp"
#include "Debug.hpp"

int	test00(){
	msgTest(" Test 00 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Orthodox Canonical Form Bureaucrat:\n");

	std::string name = getName();
	if (name.empty())
		name += "default";
	Debug::stop = 0;
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureaucrat A(name, 1);\n");
		Bureaucrat A(name, 1);
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureaucrat B(A);\n");
		Bureaucrat B(A);
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureaucrat C;\n");
		Bureaucrat C;
		Debug::msg(1, ITALI SUBLI CYAN "\n    C = A;\n");
		C = A;
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << A;\n");
		std::cout << A << '\n';
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << A.getGrade() << '\\n';\n");
		std::cout << A.getGrade() << '\n';
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << A.getName() << '\\n';\n");
		std::cout << A.getName() << "\n\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 1;	
	}
	Debug::stop = 1;
	return (0);
}
