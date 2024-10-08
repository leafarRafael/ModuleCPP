/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:34:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Debug.hpp"
#include "Color.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstddef>

//************************************************************************************
//********************************* Member function **********************************
//************************************************************************************

AForm *Intern::makeForm(std::string nameForm, std::string targeForm){
	if (nameForm.empty() || targeForm.empty())
		return 0;
	for(int i = 0; i < 3; i++)
	{
		if (nameForm == this->_allForm[i].form)
			return (this->_allForm[i].function(targeForm));
	}
	return 0;
}

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
Intern::~Intern(){
	if (_allForm != NULL)
		delete[] this->_allForm;
	Debug::msgOrthodox(1, BLUE "Destructor Intern is called.\n");
}

Intern::Intern(){
	Debug::msgOrthodox(1, BLUE "Constructor default Intern is called.\n");
	this->_allForm = new PtrForm[3];
	this->_allForm[PRESIDENTIAL].form = "PresidentialPardonForm";
	this->_allForm[PRESIDENTIAL].function = Intern::presidentialPardonForm;
	this->_allForm[ROBOTOMY].form = "RobotomyRequestForm";
	this->_allForm[ROBOTOMY].function = Intern::robotomyRequestForm;
	this->_allForm[SHRUBBERY].form = "ShrubberyCreationForm";
	this->_allForm[SHRUBBERY].function = Intern::shrubberyCreationForm;
}

Intern::Intern(Intern const &inter){
	Debug::msgOrthodox(1, BLUE "Copy constructor Intern is called.\n");
	this->_allForm = new PtrForm[3];
	Intern::cpyAllForm(this->_allForm, inter.getAllForm());
}

Intern &Intern::operator=(Intern const &inter){
	Debug::msgOrthodox(1, BLUE "Copy assignment Intern is called \n");
	if (this != &inter)
	{
		if (this->_allForm != NULL)
			delete[] this->_allForm;
		this->_allForm = new PtrForm[3];
		Intern::cpyAllForm(this->_allForm, inter.getAllForm());		
	}
	return *this;
}

PtrForm*	Intern::getAllForm() const{
	return this->_allForm;
}

AForm *Intern::presidentialPardonForm(std::string _target){
	return (new PresidentialPardonForm(_target));
}

AForm *Intern::robotomyRequestForm(std::string _target){
	return (new RobotomyRequestForm(_target));
}

AForm *Intern::shrubberyCreationForm(std::string _target){
	return (new ShrubberyCreationForm(_target));
}

void	Intern::cpyAllForm(PtrForm *dest, PtrForm *origin){
	for (int i = 0; i < 3; i++){
		dest[i].form = origin[i].form;
		dest[i].function = origin[i].function;
	}
}
