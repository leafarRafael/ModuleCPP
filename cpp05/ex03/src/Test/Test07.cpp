/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test07.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:57:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "AForm.hpp"
#include "Debug.hpp"

int	test07(){
	msgTest(" Test 07 ");
	std::string name = getName();
	if (name.empty())
		name += "default";

	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   grade_sign and _grade_execute Margins: \n");
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    AForm A(name, 1, 1);\n");
		AForm A(name, 1, 1);
		std::cout << A << '\n';
	
		Debug::msg(1, ITALI SUBLI CYAN "\n    AForm B(name, 150, 150);\n");
		AForm B(name.append(" 3"), 150, 150);
		std::cout << B << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 1;	
	}
	return (0);
}
