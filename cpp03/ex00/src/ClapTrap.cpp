/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:09:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/05 17:14:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "Collor.hpp"
#include <iostream>

//************************************************************************************
//******************************* Public Member Functions ****************************
//************************************************************************************

void	ClapTrap::attack(const std::string& target){
	if (!this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " no have energy to attack.\n";
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			<< ", cousing " << this->_attackDamage << " points of damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (!this->_energyPoints){
		std::cout << "ClapTrap " << this->_name << " no have energy to repaired.\n";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " Repaired "
			<< amount << " life points ";
	this->_hitPoints += amount;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " + this->_name + " Received " << amount << " damage; ";
	std::cout << "[ Healtlife " << this->_hitPoints << " ]" << std::endl;
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
	 	this->_hitPoints -= amount;
}
//____________________________________________________________________________________

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************

//* Destructor
ClapTrap::~ClapTrap(){
	std::cout << BLUE  "The destructor lived up to its name and wiped out " RESET << this->_name << std::endl;
	std::cout << "________________________________________________________________\n\n";
}
//* Copy constructor
ClapTrap::ClapTrap(const ClapTrap & origin){
	std::cout << BLUE "Copy constructor called " RESET << std::endl;
	std::cout << "________________________________________________________________\n\n";
	this->_name = origin.getName();
	this->_hitPoints = origin.getHitPoints();
	this->_energyPoints = origin.getEnergyPoints();
	this->_attackDamage = origin.getAttackDamage();
	
}

//* Constructor default
ClapTrap::ClapTrap(){
	std::cout << BLUE "Constructor default called" RESET << std::endl;
	std::cout << "________________________________________________________________\n\n";
	this->_name = "";
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
}

//* Constructor with parameter name
ClapTrap::ClapTrap(std::string name):_name(name){
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	std::cout << BLUE  "Constructor with name called " RESET << _name << std::endl;
	std::cout << "________________________________________________________________\n\n";
}

//* Copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap & origin){
	std::cout << BLUE "Copy assignment constructor called" RESET << std::endl;
	std::cout << "________________________________________________________________\n\n";
	this->_name = origin._name;
	this->_attackDamage = origin._attackDamage;
	this->_energyPoints = origin._energyPoints;
	this->_hitPoints = origin._hitPoints;
	return (*this);
}
//____________________________________________________________________________________



//************************************************************************************
//********************************* Methods Geters ***********************************
//************************************************************************************
std::string	ClapTrap::getName() const {
	return (this->_name);
}

int			ClapTrap::getHitPoints() const{
	return (this->_hitPoints);
}

int			ClapTrap::getEnergyPoints() const{
	return (this->_energyPoints);
}

int			ClapTrap::getAttackDamage() const{
	return (this->_attackDamage);
}
//____________________________________________________________________________________



//************************************************************************************
//********************************* Methods Seters ***********************************
//************************************************************************************
void				ClapTrap::setName(std::string name){
	std::cout << BLUE "setName called" RESET << std::endl;
	std::cout << "________________________________________________________________\n\n";
	this->_name = name;
}

void				ClapTrap::setHitPoints(int hitPoints){
	std::cout << BLUE "setHitPoints called" RESET << std::endl;
	std::cout << "________________________________________________________________\n\n";
	this->_hitPoints = hitPoints;
}

void				ClapTrap::setEnergyPoints(int energyPoints){
	std::cout << BLUE "setEnergyPoints called" RESET << std::endl;
	std::cout << "________________________________________________________________\n\n";
	this->_energyPoints = energyPoints;
}

void				ClapTrap::setAttackDamage(int attackDamage){
	std::cout << BLUE "setAttackDamage called" RESET << std::endl;
	std::cout << "________________________________________________________________\n\n";
	this->_attackDamage = attackDamage;
}
//____________________________________________________________________________________