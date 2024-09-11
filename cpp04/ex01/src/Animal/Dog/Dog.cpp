/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 17:46:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Color.hpp"

static void msg(std::string msg);

Dog::~Dog(){
	delete this->_brain;
	msg("Destructor ");
}

Dog::Dog():Animal(){
	msg("Constructor ");
	this->_brain = new Brain();
	this->_type = DOG;
}

Dog::Dog(const Dog & origin) : Animal(origin){
	msg("Copy Constructor ");
	this->_brain = new Brain();
	*this->_brain = *origin._brain;
	this->_type = DOG;
}

Dog &Dog::operator=(const Dog & origin){
	msg("Copy assignment operator ");
	if (this != &origin){
		Animal::operator=(origin);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
		*this->_brain = *origin._brain;
		this->_type = DOG;
	}
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << DOG_ASCII << '\n';
}
	
std::string Dog::getName(){
	return (this->_type);
}

Brain* Dog::getBrain() const
{
	return (this->_brain);
}


static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< DOG
		<< BLUE << " is called" << RESET
		<< std::endl;
}