/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:41:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/16 15:13:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){};

Zombie::~Zombie()
{
	std::cout << _name << '\n';
};

void		Zombie::announce( void )
{
	std::cout << _name << ": Braiiiiiiinnnzzz" << '\n';
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	announce();
}