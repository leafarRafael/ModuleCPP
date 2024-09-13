/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:30:15 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 14:38:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>
#include "Color.hpp"
#include "ICharacter.hpp"
#include "Debug.hpp"

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
Ice::~Ice(){
	Debug::msgOrthodox(6, BLUE, "Destructor ", RESET, ICE, BLUE, " is called \n");
}

Ice::Ice():AMateria(){
	Debug::msgOrthodox(6, BLUE, "Constructor default ", RESET, ICE, BLUE, " is called \n");
	this->_type = ICE;
}

Ice::Ice(const Ice & origin):AMateria(origin){
	Debug::msgOrthodox(6, BLUE, "Copy constructor ", RESET, ICE, BLUE, " is called \n");
	this->_type = ICE;
}

Ice &Ice::operator=(const Ice & origin){
	if (this != &origin)
	{
		AMateria::operator=(origin);
		Debug::msgOrthodox(6, BLUE, "Copy assignment ", RESET, ICE, BLUE, " is called \n");
		this->_type = ICE;
	}
	else 
		Debug::msgOrthodox(6, BLUE, "Copy assignment ", RESET, ICE, BLUE, " is called \n");
	return (*this);
}

//**************************************************************************************
//******************************* Override methods AMateria ****************************
//**************************************************************************************
AMateria* Ice::clone() const{
	Debug::msgOrthodox(6, BLUE, "Clone ", RESET, ICE, BLUE, " is called \n");;
	AMateria *newIceAMateria = new Ice();
	return (newIceAMateria);
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << '\n' ;
}
