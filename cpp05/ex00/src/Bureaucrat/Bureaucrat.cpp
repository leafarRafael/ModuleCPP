/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:44:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/04 18:15:26 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <string>

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************

Bureucrat::~Bureucrat(){
	Debug::msgOrthodox(1, BLUE "Destructor is called \n");
}

Bureucrat::Bureucrat():_name("Object defult"),_grade(LOWEST_GRADE){
	Debug::msgOrthodox(1, BLUE "Constructor default is called \n");
}

Bureucrat::Bureucrat(std::string const name, int grade):_name(name){
	Debug::msgOrthodox(1, BLUE "Constructor with name and grade is called \n");
	if (grade < HIGHEST_GRADE)
		throw (Bureucrat::GradeTooHighException());
	if (grade > LOWEST_GRADE)
		throw (Bureucrat::GradeTooLowException());
	this->_grade = grade;
}

Bureucrat::Bureucrat(Bureucrat const &origin):_name(origin.getName()){
	Debug::msgOrthodox(1, BLUE "Copy constructor is called \n");
	this->_grade = origin.getGrade();
}

Bureucrat &Bureucrat::operator=(Bureucrat const & origin){
	if (this != &origin){
		this->_grade = origin.getGrade();
	}
	Debug::msgOrthodox(1, BLUE "Copy assignment is called \n");
	return *this;
}

//************************************************************************************
//********************************* Methods geters ***********************************
//************************************************************************************

const std::string & Bureucrat::getName() const{
	return _name;
}

int			Bureucrat::getGrade() const{
	return _grade;
}

//************************************************************************************
//********************************* Overload of the insertion («) ********************
//************************************************************************************

std::ostream &operator<<(std::ostream & os, const Bureucrat & burr){
	os << burr.getName() << ", bureucrat grade [" << burr.getGrade() << ']' << '\n';
	return (os);
}


//************************************************************************************
//********************************* Overload exception *******************************
//************************************************************************************

const char *Bureucrat::GradeTooHighException::what() const throw(){
	return (RED "Grade too high exception\n" RESET);
}

const char *Bureucrat::GradeTooLowException::what() const throw(){
	return (RED "Grade too low exception\n" RESET);	
}


//************************************************************************************
//********************************* Methods increment decrement **********************
//************************************************************************************

void	Bureucrat::increment(){
	if ((_grade - 1) < HIGHEST_GRADE)
		throw (Bureucrat::GradeTooHighException());
	this->_grade--;
}

void	Bureucrat::decrement(){
	if ((_grade + 1) > LOWEST_GRADE)
		throw (Bureucrat::GradeTooLowException());
	this->_grade++;
}
