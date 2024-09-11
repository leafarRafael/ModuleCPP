/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 09:26:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Collor.hpp"

Animal::~Animal(){
	std::cout
		<< BLUE << "Destructor " << RESET
		<< ANIMAL 
		<< BLUE << " is called" << RESET
		<< std::endl;
}

Animal::Animal():_type(ANIMAL){
	std::cout
		<< BLUE << "Constructor " << RESET
		<< ANIMAL 
		<< BLUE << " is called" << RESET
		<< std::endl;
}

Animal::Animal(const Animal & origin){
	std::cout
		<< BLUE << "Copy constructor " << RESET
		<< ANIMAL 
		<< BLUE << " is called" << RESET
		<< std::endl;
	this->_type = origin._type;
}


Animal &Animal::operator=(const Animal & origin){
	if (this != &origin)
	{
		std::cout
			<< BLUE <<  "Copy assignment operator " << RESET
			<< ANIMAL 
			<< BLUE << " is called" << RESET
			<< std::endl;
		this->_type = origin._type;
	}
	return (*this);
}

void Animal::makeSound() const{
	std::cout << "But the sound of which " << ANIMAL << '?' << std::endl;
}

std::string	Animal::getType() const {
	return (this->_type);
}
