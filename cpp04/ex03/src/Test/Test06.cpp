/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test06.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 16:50:38 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "test.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

static void unequip(ICharacter *ptr);
static void equip(ICharacter *ptr);
static void use(ICharacter *ptr1, ICharacter *ptr2);

int test06(){
	msgTest(" Test Methods equip(), unequip() and use() class Character");

	Debug::msg(3, ITALI, CYAN, "ICharacter *player1 = new Character(\"player1\");\n");
	ICharacter *player1 = new Character("player1");
	Debug::msg(3, ITALI, CYAN, "ICharacter *player2 = new Character(\"player2\");\n");
	ICharacter *player2 = new Character("player2");
	unequip(player2);
	equip(player1);
	use(player1, player2);
	delete player1;
	delete player2;
	return (0);
}

static void equip(ICharacter *ptr){
	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   equip():\n");
	Debug::msg(3, ITALI, CYAN ,"Ice *ice = new Ice();\n");
	Ice *ice = new Ice();
	Debug::msg(3, ITALI, CYAN ,"Cure *cure = new Cure();\n");
	Cure *cure = new Cure();

	Debug::msg(3, ITALI, CYAN ,"2 times ptr->equip(ice);\n");
	Debug::msg(3, ITALI, CYAN ,"2 times ptr->equip(cure);\n");
	ptr->equip(ice);
	ptr->equip(cure);
	ptr->equip(ice);
	ptr->equip(cure);
	Debug::msg(3, ITALI, CYAN ,"\nptr->equip(new Ice());\n");
	ptr->equip(new Ice());
	Debug::msg(3, ITALI, CYAN ,"\nptr->equip(new Cure());\n");
	ptr->equip(new Cure());
	Debug::msg(3, ITALI, CYAN ,"\nstatic_cast<Character*>(ptr)->showInventory();\n");
	static_cast<Character*>(ptr)->showInventory();
}

static void use(ICharacter *ptr1, ICharacter *ptr2){
	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   use():\n");
	Debug::msg(3, ITALI, CYAN ,"\nptr1->use(0, *ptr2);\n");
	ptr1->use(0, *ptr2);
	Debug::msg(3, ITALI, CYAN ,"\nptr1->use(1, *ptr2);\n");
	ptr1->use(1, *ptr2);
	Debug::msg(3, ITALI, CYAN ,"\nptr1->use(2, *ptr2);\n");
	ptr1->use(2, *ptr2);
	Debug::msg(3, ITALI, CYAN ,"\nptr1->use(3, *ptr2);\n");
	ptr1->use(3, *ptr2);
	Debug::msg(3, ITALI, CYAN ,"\nptr1->use(4, *ptr2);\n");
	ptr1->use(4, *ptr2);
	Debug::msg(3, ITALI, CYAN ,"\nptr1->use(-1, *ptr2);\n");
	ptr1->use(-1, *ptr2);
}

static void unequip(ICharacter *ptr){
	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   unequip():\n");
	Debug::msg(3, ITALI, CYAN ,"Ice *ice = new Ice();\n");
	Ice *ice = new Ice();
	Debug::msg(3, ITALI, CYAN ,"Cure *cure = new Cure();\n");
	Cure *cure = new Cure();

	Debug::msg(3, ITALI, CYAN ,"ptr->equip(ice);\n");
	Debug::msg(3, ITALI, CYAN ,"ptr->equip(cure);\n");
	ptr->equip(cure);
	ptr->equip(ice);
	Debug::msg(3, ITALI, CYAN ,"ptr->unequip(2);\n");
	ptr->unequip(2);
	Debug::msg(3, ITALI, CYAN ,"ptr->unequip(3);\n");
	ptr->unequip(3);
	Debug::msg(3, ITALI, CYAN ,"ptr->unequip(4);\n");
	ptr->unequip(4);
	Debug::msg(3, ITALI, CYAN ,"ptr->unequip(-1);\n");
	ptr->unequip(-1);
	Debug::msg(3, ITALI, CYAN ,"ptr->unequip(0);\n");
	ptr->unequip(0);
	Debug::msg(3, ITALI, CYAN ,"ptr->unequip(1);\n");
	ptr->unequip(1);
	delete ice;
	delete cure;

}