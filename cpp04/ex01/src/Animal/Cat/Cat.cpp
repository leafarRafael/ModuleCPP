/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 17:46:03 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Color.hpp"

static void msg(std::string msg);

Cat::~Cat(){
	delete this->_brain;
	msg("Destructor ");
}

Cat::Cat():Animal(){
	msg("Constructor ");
	this->_brain = new Brain();
	this->_type = CAT;
}
Cat::Cat(const Cat & origin) : Animal(origin){
	msg("Copy Constructor ");
	this->_brain = new Brain();
	*this->_brain = *origin._brain;;
	this->_type = CAT;
}
Cat &Cat::operator=(const Cat & origin) {
	msg("Copy assignment operator ");
	if (this != &origin)
	{
		Animal::operator=(origin); 
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
		*this->_brain = *origin._brain;
		this->_type = CAT;	
	}
	return (*this);
}
void	Cat::makeSound() const {
	std::cout << ASCII_CAT  << "\n\n";
}

std::string	Cat::getType() const{
	return (this->_type);
}

Brain* Cat::getBrain() const
{
	return (this->_brain);
}

static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< CAT
		<< BLUE << " is called" << RESET
		<< std::endl;
}