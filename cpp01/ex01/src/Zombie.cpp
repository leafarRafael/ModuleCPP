/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:41:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/30 08:57:16 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){};

Zombie::~Zombie()
{
	std::cout << _name << " called destructor\n";
}

void		Zombie::announce( void )
{
	std::cout << _name << ": Braiiiiiiinnnzzz" << '\n';
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	announce();
}