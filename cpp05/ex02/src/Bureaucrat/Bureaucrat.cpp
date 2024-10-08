/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 10:30:51 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Debug.hpp"
#include "Color.hpp"
#include "AForm.hpp"

//************************************************************************************
//********************************* Member function **********************************
//************************************************************************************
void	Bureaucrat::signForm(AForm &obj_form){
	try{
		obj_form.beSigned(*this);
		Debug::msg(3, MAGENTA ITALI BOLD SUBLI, this->getName().c_str(), RESET " ");
		Debug::msg(1, " sign ");
		Debug::msg(3, MAGENTA ITALI BOLD SUBLI, obj_form.getName().c_str(), RESET "\n");
	}catch(AForm::AFormException &e){
		std::cerr << "Bureaucrat: "
			<< MAGENTA ITALI BOLD SUBLI << this->getName().c_str() << RESET " "
			<< " couldn’t sign "
			<< MAGENTA ITALI BOLD SUBLI << obj_form.getName().c_str() << RESET " "
			<< e.what();
		throw  Bureaucrat::UnsignedForm();	
	}
}

void	Bureaucrat::executeForm(AForm const & form){
	try{
		form.execute(*this);
		Debug::msg(1, "Bureaucrat: ");
		Debug::msg(3, MAGENTA ITALI BOLD SUBLI, this->getName().c_str(), RESET " ");
		Debug::msg(1, " executed ");
		Debug::msg(3, MAGENTA ITALI BOLD SUBLI, form.getName().c_str(), "\n");
	}catch (std::exception &e){
		std::cerr << "Bureaucrat: "
			<< MAGENTA ITALI BOLD SUBLI << this->getName().c_str() << RESET " "
			<< " couldn’t execute "
			<< MAGENTA ITALI BOLD SUBLI << form.getName().c_str() << RESET " "
			<< e.what();
		throw  Bureaucrat::FormNoTExecuted();	
	}
}

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

const char *Bureaucrat::UnsignedForm::what() const throw(){
	return (RED ITALI SUBLI "Unsigned Form.\n" RESET);
}

const char *Bureaucrat::FormNoTExecuted::what() const throw(){
	return (RED ITALI SUBLI "Form not executed.\n" RESET);
}

//************************************************************************************
//********************************* Overload of the insertion («) ********************
//************************************************************************************
std::ostream &operator<<(std::ostream &os, const Bureaucrat &burr){
	os << "Name: " RED ITALI SUBLI BOLD << burr.getName() << "\n" RESET
		<< "Grade: " RED ITALI BOLD << burr.getGrade() << "\n" RESET;
	return (os);
}

