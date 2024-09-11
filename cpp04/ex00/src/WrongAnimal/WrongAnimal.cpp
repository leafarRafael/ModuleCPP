/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 09:30:45 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "Collor.hpp"

WrongAnimal::~WrongAnimal(){
	std::cout
		<< BLUE << "Destructor " << RESET
		<< WRONG_ANIMAL 
		<< BLUE << " is called" << RESET
		<< std::endl;
}

WrongAnimal::WrongAnimal():_type(WRONG_ANIMAL){
	std::cout
		<< BLUE << "Constructor " << RESET
		<< WRONG_ANIMAL
		<< BLUE << " is called" << RESET
		<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & origin){
	std::cout
		<< BLUE << "Copy constructor " << RESET
		<< WRONG_ANIMAL
		<< BLUE << " is called" << RESET
		<< std::endl;
	this->_type = origin._type;
}


WrongAnimal &WrongAnimal::operator=(const WrongAnimal & origin){
	if (this != &origin)
	{
		std::cout
			<< BLUE <<  "Copy assignment operator " << RESET
			<< WRONG_ANIMAL
			<< BLUE << " is called" << RESET
			<< std::endl;
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
