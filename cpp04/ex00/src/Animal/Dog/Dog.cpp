/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 09:18:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Collor.hpp"

Dog::~Dog(){
	std::cout
	<< BLUE << "Destructor " << RESET
	<< DOG
	<< BLUE << " is called" << RESET
	<< std::endl;
}

Dog::Dog():Animal(){
	std::cout
		<< BLUE << "Constructor " << RESET
		<< DOG 
		<< BLUE << " is called" << RESET
		<< std::endl;
	this->_type = DOG;
}

Dog::Dog(const Dog & origin) : Animal(origin){
	std::cout
		<< BLUE << "Copy constructor " << RESET
		<< DOG
		<< BLUE << " is called" << RESET
		<< std::endl;
	this->_type = DOG;
}

Dog &Dog::operator=(const Dog & origin){
	Animal::operator=(origin);
	std::cout
		<< BLUE <<  "Copy assignment operator " << RESET
		<< DOG
		<< BLUE << " is called" << RESET
		<< std::endl;
	this->_type = DOG;
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << DOG_ASCII << '\n';
}
	
std::string Dog::getName(){
	return (this->_type);
}
