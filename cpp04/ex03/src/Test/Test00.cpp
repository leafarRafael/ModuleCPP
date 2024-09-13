/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 14:46:16 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

int	test00(){
	msgTest(" Test AMateria Cure ");

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances constructor default Cure:\n");
	Debug::msg(3, ITALI, CYAN ,"Cure *cure = new Cure();\n");
	Cure *cure = new Cure();

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances copy constructor Cure:\n");
	Debug::msg(3, ITALI, CYAN ,"AMateria *ptrAmateria = new Cure();\n");
	AMateria *ptrAmateria = new Cure(*cure);

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances copy assingment Cure:\n");
	Debug::msg(3, ITALI, CYAN ,"Cure *ptrCure = new Cure();\n");
	Cure *ptrCure = new Cure();
	Debug::msg(3, ITALI, CYAN ,"ptrCure = cure;\n");
	*ptrCure = *cure;

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   clone() Cure:\n");
	Debug::msg(3, ITALI, CYAN ,"Cure *clone = ptrAmateria->clone();\n");
	AMateria *clone = ptrAmateria->clone();

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   getType() Cure:\n");
	Debug::msg(4, ITALI, CYAN , "clone->getType() = ", clone->getType().c_str());

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n\n   Destructor Cure:\n");
	delete ptrAmateria;
	delete ptrCure;
	delete cure;
	delete clone;
	return (0);
}
