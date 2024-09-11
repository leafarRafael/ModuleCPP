/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 09:36:14 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Collor.hpp"

WrongCat::~WrongCat() {
	std::cout
	<< BLUE << "Destructor " << RESET
	<< WRONG_CAT
	<< BLUE << " is called" << RESET
	<< std::endl;
}
WrongCat::WrongCat(): WrongAnimal(){
	std::cout
		<< BLUE << "Constructor " << RESET
		<< WRONG_CAT 
		<< BLUE << " is called" << RESET
		<< std::endl;
	this->_type = WRONG_CAT;
}
WrongCat::WrongCat(const WrongCat & origin) :  WrongAnimal(origin) {
	std::cout
		<< BLUE << "Copy constructor " << RESET
		<< WRONG_CAT
		<< BLUE << " is called" << RESET
		<< std::endl;
	this->_type = WRONG_CAT;
}
WrongCat &WrongCat::operator=(const WrongCat & origin) {
	WrongAnimal::operator=(origin); 
	std::cout
		<< BLUE <<  "Copy assignment operator " << RESET
		<< WRONG_CAT
		<< BLUE << " is called" << RESET
		<< std::endl;
	this->_type = WRONG_CAT;
	return (*this);
}
void	WrongCat::makeSound() const {
	std::cout << ASCII_WRONG_CAT << std::endl;
}

std::string	WrongCat::getType() const{
	return (this->_type);
}