/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:53:38 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Bureaucrat.hpp"
#include "Debug.hpp"

int	test01(){
	msgTest(" Test 01 ");

	std::string name = getName();
	if (name.empty())
		name += "default";
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Grid Value Margins:\n");
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureaucrat A(name, 1);\n");
		Bureaucrat A(name, 1);
		std::cout << A << '\n';
	
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureaucrat B(name.append(\"2\"), 150);\n");
		Bureaucrat B(name.append("2"), 150);
		std::cout << B << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 1;	
	}
	return (0);
}
