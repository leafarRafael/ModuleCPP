/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 14:39:48 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Color.hpp"

static void msg(std::string msg);

Animal::~Animal(){
	msg("Destructor ");
}

Animal::Animal():_type(ANIMAL){
	msg("Constructor ");
}

Animal::Animal(const Animal & origin){
	msg("Copy constructor ");
	this->_type = origin._type;
}


Animal &Animal::operator=(const Animal & origin){
	msg("Copy assignment operator ");
	if (this != &origin)
		this->_type = origin._type;
	return (*this);
}

void Animal::makeSound() const{
	std::cout << "But the sound of which " << ANIMAL << '?' << std::endl;
}

std::string	Animal::getType() const {
	return (this->_type);
}

static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< ANIMAL
		<< BLUE << " is called" << RESET
		<< std::endl;
}