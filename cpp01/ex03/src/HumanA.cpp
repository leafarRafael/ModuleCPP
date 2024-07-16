/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:37:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/16 20:41:10 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>

HumanA::~HumanA(){};

HumanA::HumanA(std::string name, Weapon& weapon):
_name(name), _weapon(weapon)
{};

void HumanA::attack() const
{
	std::cout << this->_name << " attacks with their " << _weapon.getType() << '\n';
}