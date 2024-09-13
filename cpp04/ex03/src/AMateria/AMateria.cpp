/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:00:55 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 14:32:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Color.hpp"
#include "ICharacter.hpp"
#include "Debug.hpp"

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
AMateria::~AMateria(){
	Debug::msgOrthodox(6, BLUE, "Destructor ", RESET, AMATERIA, BLUE, " is called \n");
}

AMateria::AMateria():_type(AMATERIA){
	Debug::msgOrthodox(6, BLUE, "Constructor default ", RESET, AMATERIA, BLUE, " is called \n");
}

AMateria::AMateria(std::string const & type):_type(type){
	Debug::msgOrthodox(6, BLUE, "Constructor with type ", RESET, AMATERIA, BLUE, " is called \n");
}

AMateria::AMateria(const AMateria & origin){
	Debug::msgOrthodox(6, BLUE, "Copy constructor ", RESET, AMATERIA, BLUE, " is called \n");
	this->_type = origin._type;
}

AMateria &AMateria::operator=(const AMateria & origin){
	if (this != &origin)
	{
		Debug::msgOrthodox(6, BLUE, "Copy assignment ", RESET, AMATERIA, BLUE, " is called \n");
		this->_type = origin._type;
	}
	else
		Debug::msgOrthodox(6, BLUE, "Copy assignment ", RESET, AMATERIA, BLUE, " is called \n");
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
