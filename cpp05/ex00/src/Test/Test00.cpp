/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/04 18:18:07 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Bureaucrat.hpp"
#include "Debug.hpp"

int	test00(){
	msgTest(" Test 00 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Instances constructor Bureucrat:\n");

	Debug::stop = 0;
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureucrat A(\"Hermes Conrad\", 1);\n");
		Bureucrat A("Hermes Conrad", 1);
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureucrat B(A);\n");
		Bureucrat B(A);
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureucrat C;\n");
		Bureucrat C;
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
