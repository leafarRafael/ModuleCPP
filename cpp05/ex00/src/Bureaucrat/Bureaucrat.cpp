/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/07 11:25:08 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Debug.hpp"
#include "Color.hpp"

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
Bureaucrat::~Bureaucrat(){
	Debug::msgOrthodox(1, BLUE "Destructor Bureaucrat is called.\n");
}

Bureaucrat::Bureaucrat():_name("Constructor default Bureaucrat"), _grade(150){
	Debug::msgOrthodox(1, BLUE "Constructor default Bureaucrat is called.\n");
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade){
	Debug::msgOrthodox(1, BLUE "Constructor Bureaucrat with parameters is called.\n");
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &burr):_name(burr.getName()), _grade(burr.getGrade()){
	Debug::msgOrthodox(1, BLUE "Copy constructor Bureaucrat is called.\n");
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &burr){
	if (this != &burr)
		this->_grade = burr.getGrade();
	Debug::msgOrthodox(1, BLUE "Copy assignment Bureaucrat is called \n");
	return *this;
}

//************************************************************************************
//********************************* Methods geters ***********************************
//************************************************************************************
const std::string	&Bureaucrat::getName() const{
	return (this->_name);
}

int					Bureaucrat::getGrade() const{
	return (this->_grade);
}

void				Bureaucrat::incrementGrade(){
	if ((this->_grade +1) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void				Bureaucrat::decrementGrade(){
	if ((this->_grade - 1 ) < 1)
		throw Bureaucrat::GradeTooHighException(); 
	this->_grade--;
}


//************************************************************************************
//********************************* Overload exception *******************************
//************************************************************************************
const char *Bureaucrat::BureaucratException::what() const throw(){
	return (RED ITALI SUBLI "Default exception.\n" RESET);
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return (RED ITALI SUBLI "Grade too high exception.\n" RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return (RED ITALI SUBLI "Grade too Low exception.\n" RESET);
}

//************************************************************************************
//********************************* Overload of the insertion («) ********************
//************************************************************************************
std::ostream &operator<<(std::ostream &os, const Bureaucrat &burr){
	os << "Name: " RED ITALI SUBLI BOLD << burr.getName() << "\n" RESET
		<< "Grade: " RED ITALI BOLD << burr.getGrade() << "\n" RESET;
	return (os);
}