/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:11:34 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:49:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Debug.hpp"
#include "Color.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>
#include "unistd.h"

//************************************************************************************
//********************************* Member function **********************************
//************************************************************************************

void	PresidentialPardonForm::howToRun() const {
	Debug::msg(2, RED ITALI SUBLI BOLD, this->getTarget().c_str());
	Debug::msg(1, " has been pardoned by Zaphod Beeblebrox.\n");
}

//************************************************************************************
//********************************* Member function **********************************
//************************************************************************************

PresidentialPardonForm::~PresidentialPardonForm(){
	Debug::msgOrthodox(1, BLUE "Destructor Presidential is called.\n");
}

PresidentialPardonForm::PresidentialPardonForm():
AForm("PresidentialPardonForm", SIGN_PARDON, EXEC_PARDON),
_target("_target")
{
	Debug::msgOrthodox(1, BLUE "Constructor default Presidential is called.\n");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("PresidentialPardonForm", SIGN_PARDON, EXEC_PARDON),
_target(target){
	Debug::msgOrthodox(1, BLUE "Constructor Presidential with parameters is called.\n");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidential):
AForm(presidential),
_target(presidential.getTarget()){
	if (presidential.getGradeExecute() > EXEC_PARDON || presidential.getGradeSigned() > SIGN_PARDON)
		throw AForm::GradeTooLowException();
	Debug::msgOrthodox(1, BLUE "Copy constructor Presidential is called.\n");
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidential){
	if (this != &presidential)
	{
		AForm::operator=(presidential);
		this->_target = presidential.getTarget();
	}
	Debug::msgOrthodox(1, BLUE "Copy assignment Presidential is called \n");
	if (presidential.getGradeExecute() > EXEC_PARDON || presidential.getGradeSigned() > SIGN_PARDON)
		throw AForm::GradeTooLowException();
	return *this;
}

//************************************************************************************
//********************************* Methods geters ***********************************
//************************************************************************************
std::string	PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

//************************************************************************************
//********************************* Overload exception *******************************
//************************************************************************************