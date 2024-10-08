/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test11.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 10:34:35 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Debug.hpp"
#include <ostream>

int	test11(){
	msgTest(" Test 11 ");
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   Methods signForm() generating exception:\n");
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    AForm fo(\"Potato\", 1, 1);\n");
		AForm fo("Potato", 1, 1);
		Debug::msg(1, ITALI SUBLI CYAN "\n    Bureaucrat burr(\"Hermes Conrad\", 150);\n");
		Bureaucrat burr("Hermes Conrad", 150);
		burr.signForm(fo);	
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 0;	
	}
	Debug::stop = 1;
	return (0);
}
