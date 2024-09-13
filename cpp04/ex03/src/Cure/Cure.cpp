/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:22:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 14:34:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "Color.hpp"
#include "ICharacter.hpp"
#include "Debug.hpp"

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
Cure::~Cure(){
	Debug::msgOrthodox(6, BLUE, "Destructor ", RESET, CURE, BLUE, " is called \n");
}

Cure::Cure():AMateria(){
	Debug::msgOrthodox(6, BLUE, "Constructor default ", RESET, CURE, BLUE, " is called \n");
	this->_type = CURE;
}

Cure::Cure(const Cure & origin):AMateria(origin){
	Debug::msgOrthodox(6, BLUE, "Copy constructor ", RESET, CURE, BLUE, " is called \n");
	this->_type = CURE;
}

Cure &Cure::operator=(const Cure & origin){
	if (this != &origin)
	{
		AMateria::operator=(origin);
		Debug::msgOrthodox(6, BLUE, "Copy assignment ", RESET, CURE, BLUE, " is called \n");
		this->_type = CURE;
	}
	else 
		Debug::msgOrthodox(6, BLUE, "Copy assignment ", RESET, CURE, BLUE, " is called \n");
	return (*this);
}

//**************************************************************************************
//******************************* Override methods AMateria ****************************
//**************************************************************************************
AMateria* Cure::clone() const{
	Debug::msgOrthodox(6, BLUE, "Clone ", RESET, CURE, BLUE, " is called \n");
	AMateria *newCureAMateria = new Cure();
	return (newCureAMateria);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "’s wounds *" << '\n' ;
}

//************************************************************************************
//********************************* Helper Function **********************************
//************************************************************************************
