/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:59:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 18:24:16 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Color.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

static void msg(std::string msg);
static void msgError(std::string msg, std::string color, std::string format);

//************************************************************************************
//******************************* Override methods ICharacter*************************
//************************************************************************************
void Character::equip(AMateria* m){
	if (!m)
	{
		msgError("Invalid parameter!", RED, ITALI);
		return ;
	}
	for (int i = 0; i < MAX_MATERIA ;i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			msgError("Equipped!" + this->_materia[i]->getType() + " material!", BLUE, ITALI);
			return ;
		}	
	}
	msgError("Inventory is full!", RED, ITALI);
}

void Character::unequip(int idx){
	if (idx < 0)
	{
		msgError("haha the funny man wants to convey a negative value", RED, ITALI);
		return ;
	}
	if (idx > 3)
	{
		msgError("I think I need more pockets...", RED, ITALI);
		return ;		
	}
	if (!this->_materia[idx])
		msgError("Space is already empty", RED, ITALI);
	if (this->_materia[idx])
		this->_materia[idx] = NULL;
	msgError("Materia " + this->_materia[idx]->getType() + " unequip", BLUE, RESET);
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0)
	{
		msgError("haha the funny man wants to convey a negative value", RED, ITALI);
		return ;
	}
	if (idx > 3)
	{
		msgError("I think I need more pockets...", RED, ITALI);
		return ;		
	}
	if (this->_materia[idx])
		this->_materia[idx]->use(target);
}

std::string const & Character::getName() const{
	return (this->_name);
}

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
Character::~Character(){
	this->_destroyMateria();
	msg("Destructor ");
}

Character::Character():_name(""){
	this->_initMateria();
	msg("Contructor ");
}

Character::Character(std::string name):_name(name){
	msg("Constructor with name ");
	this->_initMateria();
}

Character::Character(const Character & origin){
	msg("Constructor with name ");
	this->_initMateria();
	this->_copyMateria(origin);
}

Character &Character::operator=(const Character & origin){
	if (this != &origin)
	{
		this->_destroyMateria();
		this->_initMateria();
		this->_copyMateria(origin);
	}
	return (*this);
}

//************************************************************************************
//********************************* Helper Function **********************************
//************************************************************************************
static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< CHARACTER
		<< BLUE << " is called" << RESET
		<< std::endl;
}

static void msgError(std::string msg, std::string color, std::string format)
{
	std::cout << format + color + msg + RESET	<< std::endl;
}


void	Character::_initMateria(){
	for(int i = 0; i < MAX_MATERIA; i++)
		this->_materia[i] = NULL;
}

void	Character::_destroyMateria(){
	for(int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

void	Character::_copyMateria(const Character & origin){
	for(int i = 0; i < MAX_MATERIA; i++)
	{
		if (origin._materia[i])
			this->_materia[i] = origin._materia[i]->clone();
	}
}