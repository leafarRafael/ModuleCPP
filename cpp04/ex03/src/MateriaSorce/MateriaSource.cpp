/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:44:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 18:48:18 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

static void msg(std::string msg);
static void msgError(std::string msg, std::string color, std::string format);

//************************************************************************************
//******************************* Override methods ICharacter*************************
//************************************************************************************





//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
MateriaSource::~MateriaSource(){
	this->_destroyMateria();
	msg("Destructor ");
}

MateriaSource::MateriaSource():_name(""){
	this->_initMateria();
	msg("Contructor ");
}

MateriaSource::MateriaSource(const MateriaSource & origin){
	msg("Constructor with name ");
	this->_initMateria();
	this->_copyMateria(origin);
}

MateriaSource &MateriaSource::operator=(const MateriaSource & origin){
	if (this != &origin)
	{
		this->_destroyMateria();
		this->_initMateria();
		this->_copyMateria(origin);
	}
	return (*this);
}

//************************************************************************************
//********************************* Helper Function **********************************
//************************************************************************************
static void msg(std::string msg)
{
	std::cout
		<< BLUE << msg << RESET
		<< CHARACTER
		<< BLUE << " is called" << RESET
		<< std::endl;
}

static void msgError(std::string msg, std::string color, std::string format)
{
	std::cout << format + color + msg + RESET	<< std::endl;
}

void	MateriaSource::_initMateria(){
	for(int i = 0; i < MAX_MATERIA; i++)
		this->_materia[i] = NULL;
}

void	MateriaSource::_destroyMateria(){
	for(int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

void	MateriaSource::_copyMateria(const MateriaSource & origin){
	for(int i = 0; i < MAX_MATERIA; i++)
	{
		if (origin._materia[i])
			this->_materia[i] = origin._materia[i]->clone();
	}
}