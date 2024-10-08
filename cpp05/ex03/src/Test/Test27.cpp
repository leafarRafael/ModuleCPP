/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test27.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 15:12:37 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Intern.hpp"
#include "Debug.hpp"
#include <ostream>

int	test27(){
	msgTest(" Test 27 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Orthodox Canonical Form Intern:\n");

	Debug::stop = 0;
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    Intern intern;\n");
		Intern intern;
		Debug::msg(1, ITALI SUBLI CYAN "\n    Intern intern2(intern);\n");
		Intern intern2(intern);
		Debug::msg(1, ITALI SUBLI CYAN "\n    Intern intern3;\n");
		Intern intern3;
		Debug::msg(1, ITALI SUBLI CYAN "\n    intern2 = intern;\n");
		intern2 = intern;
		Debug::msg(1, "\n");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 1;	
	}
	Debug::stop = 1;
	return (0);
}
