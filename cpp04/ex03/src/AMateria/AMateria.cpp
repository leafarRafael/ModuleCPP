/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:00:55 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 17:08:38 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Color.hpp"
#include "ICharacter.hpp"

static void msg(std::string msg);

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
AMateria::~AMateria(){
	msg("Destructor ");
}

AMateria::AMateria():_type(AMATERIA){
	msg("Constructor ");
}

AMateria::AMateria(std::string const & type):_type(type){
	msg("Constructor with type ");
}

AMateria::AMateria(const AMateria & origin){
	msg("Copy constructor ");
	this->_type = origin._type;
}

AMateria &AMateria::operator=(const AMateria & origin){
	if (this != &origin)
	{
		msg("Copy assignment constructor ");
		this->_type = origin._type;
	}
	else
		msg("Copy constructor ");
	return (*this);
}

//**************************************************************************************
//******************************* Methods AMateria *************************************
//**************************************************************************************
std::string const & AMateria::getType() const{
	return (this->_type);
}

void AMateria::use(ICharacter& target){
	std::cout 
	<< " * He tried to do something against the "
	<< target.getName()
	<< " but failed miserably *\n";
}

//************************************************************************************
//********************************* Helper Function **********************************
//************************************************************************************
static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< AMATERIA
		<< BLUE << " is called" << RESET
		<< std::endl;
}