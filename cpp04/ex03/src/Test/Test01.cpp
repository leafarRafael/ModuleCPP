/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 12:47:08 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Ice.hpp"

static void methodsGetType(std::string callObjsct, std::string type);

int test01(){
	msgTest(" Test Methods Ortodox class Ice");
	
	msg_("Intances of Ice class", 1);
	msg_("AMateria *defalConstru = new Ice();", 2);
	AMateria *defalConstru = new Ice();
	msg_("AMateria *cpyContruct = new Ice(static_cast<Ice&>(*defalConstru));", 2);
	AMateria *cpyContruct = new Ice(static_cast<Ice&>(*defalConstru));
	msg_("AMateria *cpyAssignment = new Ice();", 2);
	AMateria *cpyAssignment = new Ice();
	msg_("static_cast<Ice&>(*cpyAssignment) = static_cast<Ice&>(*cpyContruct);", 2);
	static_cast<Ice&>(*cpyAssignment) = static_cast<Ice&>(*cpyContruct);

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
	return (0);
}

static void methodsGetType(std::string callObjsct, std::string type)
{
	std::cout << callObjsct << " = " << type << '\n';
}