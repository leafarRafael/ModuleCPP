/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test02.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/05 14:14:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Bureaucrat.hpp"
#include "Debug.hpp"

int	test02(){
	msgTest(" Test 02 ");

	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Grid value = 0, expectation that generates exception:\n");
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureaucrat A(\"Hermes Conrad A\", 0);\n");
		Bureaucrat A("Hermes Conrad A", 0);
		std::cout << A << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 0;	
	}
	return (1);
}
