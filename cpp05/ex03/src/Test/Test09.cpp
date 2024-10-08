/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test09.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:57:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "AForm.hpp"
#include "Debug.hpp"

int	test09(){
	msgTest(" Test 09 ");
	std::string name = getName();
	if (name.empty())
		name += "default";

	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   grade_sign and _grade_execute = 151, expectation that generates exception:\n");
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    AForm A(name, 151, 151);\n");
		AForm A(name, 151, 151);
		std::cout << A << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 0;	
	}
	return (1);
}
