/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 09:18:18 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Collor.hpp"

Cat::~Cat() {
	std::cout
	<< BLUE << "Destructor " << RESET
	<< CAT
	<< BLUE << " is called" << RESET
	<< std::endl;
}
Cat::Cat(): Animal(){
	std::cout
		<< BLUE << "Constructor " << RESET
		<< CAT 
		<< BLUE << " is called" << RESET
		<< std::endl;
	this->_type = CAT;
}
Cat::Cat(const Cat & origin) : Animal(origin) {
	std::cout
		<< BLUE << "Copy constructor " << RESET
		<< CAT
		<< BLUE << " is called" << RESET
		<< std::endl;
	this->_type = CAT;
}
Cat &Cat::operator=(const Cat & origin) {
	Animal::operator=(origin); 
	std::cout
		<< BLUE <<  "Copy assignment operator " << RESET
		<< CAT
		<< BLUE << " is called" << RESET
		<< std::endl;
	this->_type = CAT;
	return (*this);
}
void	Cat::makeSound() const {
	std::cout << ASCII_CAT  << "\n\n";
}

std::string	Cat::getType() const{
	return (this->_type);
}