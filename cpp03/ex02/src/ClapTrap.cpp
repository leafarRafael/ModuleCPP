/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:09:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/06 14:53:39 by rbutzke          ###   ########.fr       */
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
	std::cout << RED << "ClapTrap " << this->_name << " attacks " << target  << '!' << RESET << '\n';
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (!this->_energyPoints){
		std::cout << "ClapTrap " << this->_name << " no have energy to repaired.\n";
		return ;
	}
	if (!this->_hitPoints)
		return ;
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout 
		<< GREEN << "ClapTrap " << this->_name << " Repaired "
		<< amount << " life points;  " << RESET << '\n';
	std::cout << RED << "[Healtlife " << this->_hitPoints << ']' << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << MAGENTA << "ClapTrap " + this->_name + " Received " << amount << " damage; \n" << RESET;
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
	 	this->_hitPoints -= amount;
	std::cout << RED << "[Healtlife " << this->_hitPoints << ']' << RESET << std::endl;
	if (!this->_hitPoints)
		std::cout << "ClapTrap " << this->_name << " is dead.\n";
}

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
ClapTrap::~ClapTrap(){
	std::cout << BLUE  "Destructor ClapTrap called: " << this->_name  << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & origin){
	std::cout << BLUE << "Copy constructor ClapTrap called:\n" << RESET;
	this->_name = origin.getName();
	this->_hitPoints = origin.getHitPoints();
	this->_energyPoints = origin.getEnergyPoints();
	this->_attackDamage = origin.getAttackDamage();
}

ClapTrap::ClapTrap(){
	std::cout << BLUE << "Default constructor ClapTrap called:\n" << RESET;
	this->_name = "";
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
}

ClapTrap::ClapTrap(std::string name):_name(name){
	std::cout << BLUE << "Constructor ClapTrap with initialization parameter called:\n" << RESET;
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
}

ClapTrap &ClapTrap::operator=(const ClapTrap & origin){
	std::cout << BLUE << "ClapTrap copy assignment operator called:\n" << RESET;
	this->_name = origin._name;
	this->_attackDamage = origin._attackDamage;
	this->_energyPoints = origin._energyPoints;
	this->_hitPoints = origin._hitPoints;
	return (*this);
}

//************************************************************************************
//********************************* Methods Geters ***********************************
//************************************************************************************
std::string	ClapTrap::getName() const {
	return (this->_name);
}

int	ClapTrap::getHitPoints() const{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints() const{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage() const{
	return (this->_attackDamage);
}

//************************************************************************************
//********************************* Methods Seters ***********************************
//************************************************************************************
void	ClapTrap::setName(std::string name){
	this->_name = name;
}

void	ClapTrap::setHitPoints(int hitPoints){
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(int energyPoints){
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int attackDamage){
	this->_attackDamage = attackDamage;
}
