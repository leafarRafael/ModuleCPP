/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 12:26:26 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Ice.hpp"
#include "AMateria.hpp"

int test01(){
	msgTest(" Test AMateria Ice ");

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances constructor default Ice:\n");
	Debug::msg(3, ITALI, CYAN ,"Ice *ice = new Ice();\n");
	Ice *ice = new Ice();

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances copy constructor Ice:\n");
	Debug::msg(3, ITALI, CYAN ,"AMateria *ptrAmateria = new Ice();\n");
	AMateria *ptrAmateria = new Ice(*ice);

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances copy assingment Ice:\n");
	Debug::msg(3, ITALI, CYAN ,"Ice *ptrIce = new Ice();\n");
	Ice *ptrIce = new Ice();
	Debug::msg(3, ITALI, CYAN ,"ptrIce = ice;\n");
	*ptrIce = *ice;

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   clone() Ice:\n");
	Debug::msg(3, ITALI, CYAN ,"Ice *clone = ptrAmateria->clone();\n");
	AMateria *clone = ptrAmateria->clone();

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   getType() Ice:\n");
	Debug::msg(4, ITALI, CYAN , "clone->getType() = ", clone->getType().c_str());

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n\n   Destructor Ice:\n");
	delete ptrAmateria;
	delete ptrIce;
	delete ice;
	delete clone;
	return (0);
}
