/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:41:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/31 10:52:34 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){
	std::cout << "Call construct function for objects of class Zombie.\n";
};

Zombie::~Zombie()
{
	std::cout << "Called destructor Zombie class.\n";
}

void		Zombie::announce( void )
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}