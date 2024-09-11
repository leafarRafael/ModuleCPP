/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 15:07:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Color.hpp"

static void msg(std::string msg);

AAnimal::~AAnimal(){
	msg("Destructor ");
}

AAnimal::AAnimal():_type(AANIMAL){
	msg("Constructor ");
}

AAnimal::AAnimal(const AAnimal & origin){
	msg("Copy constructor ");
	this->_type = origin._type;
}


AAnimal &AAnimal::operator=(const AAnimal & origin){
	msg("Copy assignment operator ");
	if (this != &origin)
		this->_type = origin._type;
	return (*this);
}

std::string	AAnimal::getType() const {
	return (this->_type);
}

static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< AANIMAL
		<< BLUE << " is called" << RESET
		<< std::endl;
}