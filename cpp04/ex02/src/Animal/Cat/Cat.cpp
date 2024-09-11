/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 18:06:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Color.hpp"

static void msg(std::string msg);

Cat::~Cat(){
	delete this->_brain;
	msg("Destructor ");
}

Cat::Cat():AAnimal(){
	msg("Constructor ");
	this->_brain = new Brain();
	this->_type = CAT;
}

Cat::Cat(const Cat & origin):AAnimal(origin){
	msg("Copy Constructor ");
	this->_brain = new Brain();
	*this->_brain = *origin._brain;;
	this->_type = CAT;
}

Cat &Cat::operator=(const Cat & origin) {
	if (this != &origin)
	{
		AAnimal::operator=(origin);
		msg("Copy assignment operator ");
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
		*this->_brain = *origin._brain;
		this->_type = CAT;
	}
	else
		msg("Copy assignment operator ");
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
