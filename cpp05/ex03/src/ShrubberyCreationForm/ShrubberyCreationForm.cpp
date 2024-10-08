/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:11:34 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:43:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Debug.hpp"
#include "Color.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>

//************************************************************************************
//********************************* Member function **********************************
//************************************************************************************

void	ShrubberyCreationForm::howToRun() const {
	std::string fileName(this->_target);
	fileName.append("_shrubbery");

	std::ofstream outfile(fileName.c_str());
	if (!outfile.is_open())
		throw ShrubberyCreationForm::OpenFileException();
	outfile << TREE << std::endl << std::endl;
	outfile.close();
}

//************************************************************************************
//********************************* Member function **********************************
//************************************************************************************

ShrubberyCreationForm::~ShrubberyCreationForm(){
	Debug::msgOrthodox(1, BLUE "Destructor ShrubberyTargetDefault is called.\n");
}

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("ShrubberyCreationForm", SIGN_SHRUBEERY, EXEC_SHRUBEERY),
_target("ShrubberyTargetDefault")
{
	Debug::msgOrthodox(1, BLUE "Constructor default ShrubberyTargetDefault is called.\n");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("ShrubberyCreationFormy", SIGN_SHRUBEERY, EXEC_SHRUBEERY),
_target(target){
	Debug::msgOrthodox(1, BLUE "Constructor ShrubberyTargetDefault with parameters is called.\n");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj_shrubbery):
AForm(obj_shrubbery),
_target(obj_shrubbery.getTarget()){
	if (obj_shrubbery.getGradeExecute() > EXEC_SHRUBEERY || obj_shrubbery.getGradeSigned() > SIGN_SHRUBEERY)
		throw AForm::GradeTooLowException();
	Debug::msgOrthodox(1, BLUE "Copy constructor ShrubberyTargetDefault is called.\n");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj_shrubbery){
	if (this != &obj_shrubbery)
	{
		AForm::operator=(obj_shrubbery);
		this->_target = obj_shrubbery.getTarget();
	}
	Debug::msgOrthodox(1, BLUE "Copy assignment ShrubberyTargetDefault is called \n");
	if (obj_shrubbery.getGradeExecute() > EXEC_SHRUBEERY || obj_shrubbery.getGradeSigned() > SIGN_SHRUBEERY)
		throw AForm::GradeTooLowException();
	return *this;
}

//************************************************************************************
//********************************* Methods geters ***********************************
//************************************************************************************
std::string	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

//************************************************************************************
//********************************* Overload exception *******************************
//************************************************************************************

const char *ShrubberyCreationForm::OpenFileException::what() const throw(){
	return (RED ITALI SUBLI BOLD "Error file open\n" RESET);
}