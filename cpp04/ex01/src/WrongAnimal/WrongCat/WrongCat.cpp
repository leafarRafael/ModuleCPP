/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 13:41:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Color.hpp"

static void msg(std::string msg);

WrongCat::~WrongCat(){
	msg("Destructor ");
}

WrongCat::WrongCat(): WrongAnimal(){
	msg("Constructor ");
	this->_type = WRONG_CAT;
}

WrongCat::WrongCat(const WrongCat & origin):WrongAnimal(origin) {
	msg("Copy constructor ");
	this->_type = WRONG_CAT;
}

WrongCat &WrongCat::operator=(const WrongCat & origin){
	msg("Copy assignment operator ");
	if (this != &origin)
	{
		WrongAnimal::operator=(origin);
		this->_type = WRONG_CAT;	
	}
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << ASCII_WRONG_CAT << std::endl;
}

std::string	WrongCat::getType() const{
	return (this->_type);
}

static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< WRONG_CAT
		<< BLUE << " is called" << RESET
		<< std::endl;
}