/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:59:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 16:32:38 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Color.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include "Debug.hpp"

//************************************************************************************
//******************************* Override methods ICharacter*************************
//************************************************************************************
void Character::equip(AMateria* m){
	if (!m)
	{
		Debug::msgOrthodox(3, RED, ITALI, "Inventory is full!\n");
		return ;
	}
	for (int i = 0; i < MAX_SLOT_INVENTORY ;i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::string color = GREEN;
			if (m->getType() == "ice")
				color = CYAN;
			Debug::msgOrthodox(5, color.c_str(), ITALI, "Equipped ",
				this->_inventory[i]->getType().c_str(),	" material!\n");
			return ;
		}	
	}
	int ifDelete = 1;
	for (int i = 0; i < MAX_SLOT_INVENTORY; i++)
	{
		if (m == this->_inventory[i])
			ifDelete = 1;
	}
	if (ifDelete)
		delete m;
	Debug::msgOrthodox(3, RED, ITALI, "Inventory is full!\n");
}

void Character::unequip(int idx){
	if (idx < 0)
	{
		Debug::msgOrthodox(3, RED, ITALI, "haha the funny man wants to convey a negative value\n");
		return ;
	}
	if (idx > 3)
	{
		Debug::msgOrthodox(3, RED, ITALI, "I think I need more pockets...\n");
		return ;		
	}
	if (!this->_inventory[idx])
	{
		Debug::msgOrthodox(3, RED, ITALI, "Space is already empty!\n");
		return ;
	}
	Debug::msgOrthodox(5, BLUE, ITALI, "Materia ",
		 this->_inventory[idx]->getType().c_str()," unequip!\n");
	if (this->_inventory[idx])
		this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0)
	{
		Debug::msgOrthodox(3, RED, ITALI, "haha the funny man wants to convey a negative value\n");
		return ;
	}
	if (idx > 3)
	{
		Debug::msgOrthodox(3, RED, ITALI, "I think I need more pockets...\n");
		return ;		
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}

std::string const & Character::getName() const{
	return (this->_name);
}

void	Character::setName(std::string name){
	this->_name = name;
}

void	Character::showInventory(){
	for (int i = 0; i < MAX_SLOT_INVENTORY; i++)
	{
		if (this->_inventory[i])
			std::cout << this->_inventory[i]->getType() << '\n';
	}
}

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
Character::~Character(){
	this->_destroyMateria();
	Debug::msgOrthodox(6, BLUE, "Destructor ", RESET, CHARACTER, BLUE, " is called \n");;
}

Character::Character():_name(""){
	this->_initMateria();
	Debug::msgOrthodox(6, BLUE, "Constructor default ", RESET, CHARACTER, BLUE, " is called \n");
}

Character::Character(std::string name):_name(name){
	Debug::msgOrthodox(6, BLUE, "Constructor with name", RESET, CHARACTER, BLUE, " is called \n");;
	this->_initMateria();
}

Character::Character(const Character & origin){
	Debug::msgOrthodox(6, BLUE, "Copy constructor ", RESET, CHARACTER, BLUE, " is called \n");
	this->_initMateria();
	this->_copyMateria(origin);
}

Character &Character::operator=(const Character & origin){
	if (this != &origin)
	{
		Debug::msgOrthodox(6, BLUE, "Copy assignment ", RESET, CHARACTER, BLUE, " is called \n");
		this->_destroyMateria();
		this->_initMateria();
		this->_copyMateria(origin);
	}
	else
		Debug::msgOrthodox(6, BLUE, "Copy assignment ", RESET, CHARACTER, BLUE, " is called \n");
	return (*this);
}

//************************************************************************************
//********************************* Helper Function **********************************
//************************************************************************************
void	Character::_initMateria(){
	for(int i = 0; i < MAX_SLOT_INVENTORY; i++)
		this->_inventory[i] = NULL;
}

void	Character::_destroyMateria(){
	for(int i = 0; i < MAX_SLOT_INVENTORY; i++)
	{
		if (this->_inventory[i])
		{
			for (int x = i+1; x < MAX_SLOT_INVENTORY; x++)
			{
				if (this->_inventory[i] == this->_inventory[x])
					this->_inventory[x] = NULL;
			}
			delete this->_inventory[i];
		}
	}
}

void	Character::_copyMateria(const Character & origin){
	for(int i = 0; i < MAX_SLOT_INVENTORY; i++)
	{
		if (origin._inventory[i])
			this->_inventory[i] = origin._inventory[i]->clone();
	}
}