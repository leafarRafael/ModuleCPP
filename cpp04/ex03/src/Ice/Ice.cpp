/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:30:15 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 16:40:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>
#include "Color.hpp"
#include "ICharacter.hpp"

static void msg(std::string msg);

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
Ice::~Ice(){
	msg("Destructor ");
}

Ice::Ice():AMateria(ICE){
	msg("Constructor ");
}

Ice::Ice(const Ice & origin):AMateria(origin){
	msg("Copy constructor ");
	this->_type = ICE;
}

Ice &Ice::operator=(const Ice & origin){
	if (this != &origin)
	{
		AMateria::operator=(origin);
		msg("Copy constructor ");
		this->_type = ICE;
	}
	else 
		msg("Copy constructor ");
	return (*this);
}

//**************************************************************************************
//******************************* Override methods AMateria ****************************
//**************************************************************************************
AMateria* Ice::clone() const{
	msg("Clone ");
	AMateria *newIceAMateria = new Ice();
	return (newIceAMateria);
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << '\n' ;
}

//************************************************************************************
//********************************* Helper Function **********************************
//************************************************************************************
static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< ICE
		<< BLUE << " is called" << RESET
		<< std::endl;
}