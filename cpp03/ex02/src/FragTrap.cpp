/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:57:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/06 18:44:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "Collor.hpp"
#include <iostream>

FragTrap::~FragTrap(){
	std::cout << GREEN << "Destructor FragTrap called: " << this->getName() << RESET << std::endl;
}

FragTrap::FragTrap():ClapTrap(){
	std::cout << GREEN << "Default constructor FragTrap called:" << RESET << std::endl;
	this->setAttackDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);	
}
FragTrap::FragTrap(std::string name):ClapTrap(name){
	std::cout << GREEN << "Constructor FragTrap with initialization parameter called:" << RESET << std::endl;
	this->setAttackDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);
}

FragTrap::FragTrap(const FragTrap &origin):ClapTrap(origin){
	std::cout << GREEN << "Copy constructor FragTrap called:" << RESET << std::endl;
	this->setName(origin.getName());
	this->setAttackDamage(origin.getAttackDamage());
	this->setEnergyPoints(origin.getEnergyPoints());
	this->setHitPoints(origin.getHitPoints());
}

FragTrap &FragTrap::operator=(const FragTrap &origin){
	ClapTrap::operator=(origin);
	std::cout << GREEN << "FragTrap copy assignment operator called:" << RESET << std::endl;
	this->setName(origin.getName());
	this->setHitPoints(origin.getHitPoints());
	this->setEnergyPoints(origin.getEnergyPoints());
	this->setAttackDamage(origin.getAttackDamage());
	return (*this);
};
void FragTrap::highFivesGuys(){
	std::cout << YELLOW << "high FivesGuys !!!!" << RESET << std::endl;
};