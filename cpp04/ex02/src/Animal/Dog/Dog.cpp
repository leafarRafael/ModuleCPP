/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 18:07:26 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Color.hpp"

static void msg(std::string msg);

Dog::~Dog(){
	delete this->_brain;
	msg("Destructor ");
}

Dog::Dog():AAnimal(){
	msg("Constructor ");
	this->_brain = new Brain();
	this->_type = DOG;
}

Dog::Dog(const Dog & origin) : AAnimal(origin){
	msg("Copy Constructor ");
	this->_brain = new Brain();
	*this->_brain = *origin._brain;
	this->_type = DOG;
}

Dog &Dog::operator=(const Dog & origin){
	if (this != &origin){
		AAnimal::operator=(origin);
		msg("Copy assignment operator ");
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
		*this->_brain = *origin._brain;;
		this->_type = DOG;
	}
	else 
		msg("Copy assignment operator ");
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << DOG_ASCII << '\n';
}

Brain* Dog::getBrain() const
{
	return (this->_brain);
}

std::string Dog::getType(){
	return (this->_type);
}

static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< DOG
		<< BLUE << " is called" << RESET
		<< std::endl;
}
