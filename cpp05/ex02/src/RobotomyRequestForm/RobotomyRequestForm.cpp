/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:11:34 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/07 17:50:10 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Debug.hpp"
#include "Color.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>
#include "unistd.h"

int	RobotomyRequestForm::_chance_robotization = 1;

//************************************************************************************
//********************************* Member function **********************************
//************************************************************************************

void	RobotomyRequestForm::howToRun() const {
	_chance_robotization++;
	Debug::msg(1, "Sounds of robotization");
	for (int i = 0; i < 8; i++){
		std::cout << "." << std::flush;
		usleep(730000);
	}
	Debug::msg(1, "\n");
	if (_chance_robotization % 2 == 0){
		Debug::msg(2, RED ITALI SUBLI BOLD, this->getName().c_str());
		Debug::msg(1, " ");
		Debug::msg(1, " has been successfully robotized..\n");
	}
	else	
		throw RobotomyRequestForm::RobotomyException();
}

//************************************************************************************
//********************************* Member function **********************************
//************************************************************************************

RobotomyRequestForm::~RobotomyRequestForm(){
	Debug::msgOrthodox(1, BLUE "Destructor Robotomy is called.\n");
}

RobotomyRequestForm::RobotomyRequestForm():
AForm("Robotomy default", SIGN_ROBOT, EXEC_ROBOT),
_target("RobotomyTarget")
{
	Debug::msgOrthodox(1, BLUE "Constructor default Robotomy is called.\n");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("_robotomy", SIGN_ROBOT, EXEC_ROBOT),
_target(target){
	Debug::msgOrthodox(1, BLUE "Constructor RobotomyTwith parameters is called.\n");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomy):
AForm(robotomy),
_target(robotomy.getTarget()){
	if (robotomy.getGradeExecute() > EXEC_ROBOT || robotomy.getGradeSigned() > SIGN_ROBOT)
		throw AForm::GradeTooLowException();
	Debug::msgOrthodox(1, BLUE "Copy constructor Robotomy is called.\n");
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomy){
	if (this != &robotomy)
	{
		AForm::operator=(robotomy);
		this->_target = robotomy.getTarget();
	}
	Debug::msgOrthodox(1, BLUE "Copy assignment Robotomy is called \n");
	if (robotomy.getGradeExecute() > EXEC_ROBOT || robotomy.getGradeSigned() > SIGN_ROBOT)
		throw AForm::GradeTooLowException();
	return *this;
}

//************************************************************************************
//********************************* Methods geters ***********************************
//************************************************************************************
std::string	RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

//************************************************************************************
//********************************* Overload exception *******************************
//************************************************************************************

const char *RobotomyRequestForm::RobotomyException::what() const throw(){
	return (RED ITALI SUBLI BOLD "robotization has a 50\% chance of success.\n" RESET);
}