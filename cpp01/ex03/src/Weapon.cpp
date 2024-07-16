/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:27:47 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/16 20:32:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){};
Weapon::~Weapon(){};
Weapon::Weapon(std::string type):_type(type){};

void		Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string	Weapon::getType()
{
	return (this->_type);
}