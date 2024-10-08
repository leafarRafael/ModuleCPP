/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test06.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:56:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include <ostream>

int	test06(){
	msgTest(" Test 06 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Orthodox Canonical Form AForm:\n");
	
	std::string name = getName();
	if (name.empty())
		name += "default";
	Debug::stop = 0;
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    AForm A(name, 150, 150);\n");
		AForm A(name, 150, 150);
		Debug::msg(1, ITALI SUBLI CYAN "\n    AForm B(A);\n");
		AForm B(A);
		Debug::msg(1, ITALI SUBLI CYAN "\n    AForm C;\n");
		AForm C;
		Debug::msg(1, ITALI SUBLI CYAN "\n    C = A;\n");
		C = A;
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << A;\n");
		std::cout << A << '\n';
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << A.getName() << '\\n';\n");
		std::cout << A.getName() << "\n\n";
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << \"value [\"<< A.getIsSigned() << \"]: is \" << A.getIsSignedText() << '\\n';\n");
		std::cout << "value ["<< A.getIsSigned() << "]: is " << A.getIsSignedText() << "\n\n";
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << A.getGradeSigned() << '\\n';\n");
		std::cout << A.getGradeSigned() << "\n\n";
		Debug::msg(1, ITALI SUBLI CYAN "\n    std::cout << A.getGradeExecute() << '\\n';\n");
		std::cout << A.getGradeExecute() << "\n\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 1;	
	}
	Debug::stop = 1;
	return (0);
}
