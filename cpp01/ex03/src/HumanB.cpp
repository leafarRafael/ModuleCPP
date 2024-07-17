/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:41:42 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/17 08:02:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::~HumanB(){};

HumanB::HumanB(std::string name)
{
	_name = name;
};

HumanB::HumanB(){};

void	HumanB::attack() const
{
    std::cout << this->_name << " attacks with their " << this-> _weapon->getType() << '\n';
}

void	HumanB::setWeapon(Weapon & weapon)
{
	_weapon = &weapon;
}