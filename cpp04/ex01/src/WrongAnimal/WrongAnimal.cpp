/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 13:42:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "Color.hpp"

static void msg(std::string msg);

WrongAnimal::~WrongAnimal(){
	msg("Destructor ");
}

WrongAnimal::WrongAnimal():_type(WRONG_ANIMAL){
	msg("Constructor ");
}

WrongAnimal::WrongAnimal(const WrongAnimal & origin){
	msg("Copy constructor ");
	this->_type = origin._type;
}


WrongAnimal &WrongAnimal::operator=(const WrongAnimal & origin){
	if (this != &origin)
	{
		msg("Copy assignment operator ");
		this->_type = origin._type;
	}
	return (*this);
}

void WrongAnimal::makeSound() const{
	std::cout << "But the sound of which " << WRONG_ANIMAL << '?' << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (this->_type);
}

static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< WRONG_ANIMAL
		<< BLUE << " is called" << RESET
		<< std::endl;
}