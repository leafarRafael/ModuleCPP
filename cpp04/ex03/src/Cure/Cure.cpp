/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:22:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 16:43:32 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "Color.hpp"
#include "ICharacter.hpp"

static void msg(std::string msg);

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
Cure::~Cure(){
	msg("Destructor ");
}

Cure::Cure():AMateria(CURE){
	msg("Constructor ");
}

Cure::Cure(const Cure & origin):AMateria(origin){
	msg("Copy constructor ");
	this->_type = CURE;
}

Cure &Cure::operator=(const Cure & origin){
	if (this != &origin)
	{
		AMateria::operator=(origin);
		msg("Copy assignment constructor ");
		this->_type = CURE;
	}
	else 
		msg("Copy constructor ");
	return (*this);
}

//**************************************************************************************
//******************************* Override methods AMateria ****************************
//**************************************************************************************
AMateria* Cure::clone() const{
	msg("Clone ");
	AMateria *newCureAMateria = new Cure();
	return (newCureAMateria);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "’s wounds *" << '\n' ;
}

//************************************************************************************
//********************************* Helper Function **********************************
//************************************************************************************
static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< CURE
		<< BLUE << " is called" << RESET
		<< std::endl;
}