/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:22:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/16 11:03:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::~Zombie()
{
	std::cout << "\n" << this->_name << std::endl;
};

Zombie::Zombie(std::string name)
{
	this->_name = name;
	announce();
};

void		Zombie::announce( void )
{
	std::cout << _name << ": Braiiiiiiinnnzzz";
}
