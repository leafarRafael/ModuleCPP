/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:44:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 15:58:08 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Color.hpp"
#include "Debug.hpp"

//************************************************************************************
//******************************* Override methods ICharacter*************************
//************************************************************************************
void MateriaSource::learnMateria(AMateria* origin){
	if (!origin)
	{
		Debug::msg(3, RED, ITALI, "Invalid parameter!\n");
		return ;
	}
	for (int i = 0; i < MAX_NBR_MATERIA_SOURCE ;i++)
	{
		if (!this->_materiaSource[i])
		{
			this->_materiaSource[i] = origin;
			std::string color = GREEN;
			if (origin->getType() == "ice")
				color = MAGENTA;
			Debug::msgOrthodox(5, color.c_str(), ITALI, "Learn about ",
				this->_materiaSource[i]->getType().c_str(), "!\n");
			return ;
		}	
	}
	Debug::msg(3, RED, ITALI, "Inventory is full!\n");
	int ifDestroy = 1;
	for (int i = 0; i< MAX_NBR_MATERIA_SOURCE; i++)
	{
		if (origin == this->_materiaSource[i])
			ifDestroy = 0;
	}
	if (ifDestroy)
		delete origin;	
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < MAX_NBR_MATERIA_SOURCE; i++)
	{
		if (this->_materiaSource[i] && this->_materiaSource[i]->getType() == type)
		{
			std::string color = GREEN;
			if (type == "ice")
				color = MAGENTA;
			Debug::msgOrthodox(5, color.c_str(), ITALI, "Create ", this->_materiaSource[i]->getType().c_str(),	" success!\n");
			return (this->_materiaSource[i]->clone());
		}
	}
	Debug::msg(5, RED, ITALI, "I don't know ", type.c_str(), " sorry!");
	return (NULL);
}

void	MateriaSource::showMateria()
{
	for (int i = 0; i < MAX_NBR_MATERIA_SOURCE;i++)
	{
		if (this->_materiaSource[i])
			std::cout << this->_materiaSource[i]->getType() << '\n';
	}
}

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
MateriaSource::~MateriaSource(){
	Debug::msgOrthodox(6, BLUE, "Destructor ", RESET, MATERIASOURCE, BLUE, " is called \n");
	this->_destroyMateriaSource();
}

MateriaSource::MateriaSource(){
	Debug::msgOrthodox(6, BLUE, "Constructor default ", RESET, MATERIASOURCE, BLUE, " is called \n");
	this->_initMateriaSource();
}

MateriaSource::MateriaSource(const MateriaSource & origin){
	Debug::msgOrthodox(6, BLUE, "Copy constructor ", RESET, MATERIASOURCE, BLUE, " is called \n");
	this->_initMateriaSource();
	this->_copyMateriaSource(origin);
}

MateriaSource &MateriaSource::operator=(const MateriaSource & origin){
	if (this != &origin)
	{
		Debug::msgOrthodox(6, BLUE, "Copy assignment ", RESET, MATERIASOURCE, BLUE, " is called \n");
		this->_destroyMateriaSource();
		this->_initMateriaSource();
		this->_copyMateriaSource(origin);
	}
	else
		Debug::msgOrthodox(6, BLUE, "Copy assignment ", RESET, MATERIASOURCE, BLUE, " is called \n");
	return (*this);
}

//************************************************************************************
//********************************* Helper Function **********************************
//************************************************************************************
void	MateriaSource::_destroyMateriaSource(){
	for (int i = 0; i < MAX_NBR_MATERIA_SOURCE; i++)
	{
		if (this->_materiaSource[i])
		{
			for (int x = i+1; x < MAX_NBR_MATERIA_SOURCE; x++)
			{
				if (this->_materiaSource[i] == this->_materiaSource[x])
					this->_materiaSource[x] = NULL;
			}
			delete this->_materiaSource[i];
			this->_materiaSource[i] = NULL;
		}
	}
}

void	MateriaSource::_copyMateriaSource(const MateriaSource & origin){
	for (int i = 0; i < MAX_NBR_MATERIA_SOURCE; i++)
	{
		if (!this->_materiaSource[i])
			this->_materiaSource[i] = origin._materiaSource[i];
	}
}

void	MateriaSource::_initMateriaSource(){
	for (int i = 0; i < MAX_NBR_MATERIA_SOURCE; i++)
		this->_materiaSource[i] = NULL;
}
