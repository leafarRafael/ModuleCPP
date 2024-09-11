/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 12:48:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Cure.hpp"

static void methodsGetType(std::string callObjsct, std::string type);

int	test00(){
	msgTest(" Test Methods Ortodox class Cure");
	
	msg_("Intances of Cure class", 1);
	msg_("AMateria *defalConstru = new Cure();", 2);
	AMateria *defalConstru = new Cure();
	msg_("AMateria *cpyContruct = new Cure(static_cast<Cure&>(*defalConstru));", 2);
	AMateria *cpyContruct = new Cure(static_cast<Cure&>(*defalConstru));
	msg_("AMateria *cpyAssignment = new Cure();", 2);
	AMateria *cpyAssignment = new Cure();
	msg_("static_cast<Cure&>(*cpyAssignment) = static_cast<Cure&>(*cpyContruct);", 2);
	static_cast<Cure&>(*cpyAssignment) = static_cast<Cure&>(*cpyContruct);

	msg_("Methods getType()", 1);
	methodsGetType("defalConstru->getType()", defalConstru->getType());
	methodsGetType("cpyContruct->getType()", cpyContruct->getType());
	methodsGetType("cpyAssignment->getType()", cpyAssignment->getType());
	
	msg_("Methods clone()", 1);
	msg_("AMateria *ptr;", 2);
	AMateria *ptr;
	std::cout << "ptr = defalConstru->clone();"  << '\n';
	ptr = defalConstru->clone();

	msg_("Destructor call", 1);
	delete defalConstru;
	delete cpyContruct;
	delete cpyAssignment;
	delete ptr;
	return (0);
}

static void methodsGetType(std::string callObjsct, std::string type)
{
	std::cout << callObjsct << " = " << type << '\n';
}