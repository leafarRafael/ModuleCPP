/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:15:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/06 15:05:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Collor.hpp"
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::~ScavTrap(){
	std::cout << GREEN << "Destructor ScavTrap called: " << this->getName() << RESET << std::endl;
}

ScavTrap::ScavTrap():ClapTrap(){
	std::cout << GREEN << "Default constructor ScavTrap called:" << RESET << std::endl;
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);	
}

ScavTrap::ScavTrap(std::string _name):ClapTrap(_name){
	std::cout << GREEN << "Constructor ScavTrap with initialization parameter called:" << RESET << std::endl;
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
}

ScavTrap::ScavTrap(const ScavTrap & origin):ClapTrap(origin){
	std::cout << GREEN << "Copy constructor ScavTrap called:" << RESET << std::endl;
	this->setName(origin.getName());
	this->setHitPoints(origin.getHitPoints());
	this->setEnergyPoints(origin.getEnergyPoints());
	this->setAttackDamage(origin.getAttackDamage());
}

ScavTrap &ScavTrap::operator=(const ScavTrap & origin){
	ClapTrap::operator=(origin);
	std::cout << GREEN << "ScavTrap copy assignment operator called:" << RESET << std::endl;
	this->setName(origin.getName());
	this->setHitPoints(origin.getHitPoints());
	this->setEnergyPoints(origin.getEnergyPoints());
	this->setAttackDamage(origin.getAttackDamage());
	return (*this);
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode.\n";
}

void ScavTrap::attack(const std::string& target){
	if (!this->getEnergyPoints())
	{
		std::cout << "ScavTrap " << this->getName() << " no have energy to attack.\n";
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << RED << "ScavTrap " << this->getName() << " attacks " << target  << '!' << RESET << '\n';
}