/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test02.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 18:03:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Character.hpp"

int test02(){
	msgTest(" Test Methods Ortodox class Character");
	
	msg_("Intances of Character class", 1);
	msg_("Character *defalConstru = new Character();", 2);
	Character *defalConstru = new Character();
	msg_("Character *nameConstru = new Character(\"nameConstru\");", 2);
	Character *nameConstru = new Character("nameConstru");
	msg_("Character *cpyContruct = new Character(*nameConstru);", 2);
	Character *cpyContruct = new Character(*nameConstru);

	msg_("Character *cpyAssignment = new Character();", 2);
	msg_("*cpyAssignment = *cpyContruct;", 2);
	Character *cpyAssignment = new Character();
	*cpyAssignment = *cpyContruct;

	msg_("Destructor call", 1);
	delete defalConstru;
	delete cpyContruct;
	delete cpyAssignment;
	delete nameConstru;
	return (0);
}
