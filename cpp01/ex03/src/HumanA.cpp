/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:37:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/16 18:37:45 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>

HumanA::~HumanA(){};

HumanA::HumanA(std::string name):
_name(name)
{};

void HumanA::attack() const
{
	std::cout << this->_name << " attacks with their " << _weapon.getType() << '\n';
}