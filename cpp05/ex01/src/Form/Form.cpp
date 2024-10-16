/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:47:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/10 12:22:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Form.hpp"
#include "Debug.hpp"
#include "Bureaucrat.hpp"

//************************************************************************************
//********************************* Member function **********************************
//************************************************************************************
void	Form::beSigned(Bureaucrat &burr){
	if (burr.getGrade() > this->_grade_signed)
		throw Form::GradeTooLowException();	
	this->_is_signed = true;
}

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
Form::~Form(){
	Debug::msgOrthodox(1, BLUE "Destructor Form is called.\n");
}

Form::Form():_name("DefaultForm"), _grade_signed(150), _grade_execute(150), _is_signed(false){
	Debug::msgOrthodox(1, BLUE "Constructor default Form is called.\n");	
}

Form::Form(std::string name, int grade_signed, int grade_execute):
_name(name), _grade_signed(grade_signed), _grade_execute(grade_execute), _is_signed(false)
{
	Debug::msgOrthodox(1, BLUE "Constructor Form with parameters is called.\n");
	if (grade_signed < 1 || grade_execute < 1)
		throw Form::GradeTooHighException();
	if (grade_signed > 150 || grade_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &obj_form):
_name(obj_form.getName()), _grade_signed(obj_form.getGradeSigned()),
_grade_execute(obj_form.getGradeExecute()), _is_signed(false){
	Debug::msgOrthodox(1, BLUE "Copy constructor Form is called.\n");	
}

Form &Form::operator=(const Form &obj_form){
	if(this != &obj_form)
		this->_is_signed = obj_form.getIsSigned();
	Debug::msgOrthodox(1, BLUE "Copy assignment Form is called \n");
	return *this;
}

//************************************************************************************
//********************************* Methods geters ***********************************
//************************************************************************************
const std::string	&Form::getName() const{
	return (_name);	
}

int					Form::getGradeSigned() const{
	return (_grade_signed);
}

int					Form::getGradeExecute() const{
	return (_grade_execute);
}

bool				Form::getIsSigned() const{
	return  (_is_signed);
}

std::string			Form::getIsSignedText() const{
	if (_is_signed)
		return (BLUE ITALI BOLD "Yes" RESET);
	return (RED ITALI BOLD "Not" RESET);	
}

//************************************************************************************
//********************************* Overload exception *******************************
//************************************************************************************
const char *Form::FormException::what() const throw(){
	return (RED SUBLI ITALI "FormException default is called.\n" RESET);
}

const char *Form::GradeTooHighException::what() const throw(){
	return (RED SUBLI ITALI "Grade too high exception.\n " RESET); 
}

const char *Form::GradeTooLowException::what() const throw(){
	return (RED SUBLI ITALI "Grade too low exception.\n" RESET);
}

//************************************************************************************
//********************************* Overload of the insertion («) ********************
//************************************************************************************
std::ostream &operator<<(std::ostream &os, const Form &obj_form){
	os << "Name: " GREEN ITALI BOLD << obj_form.getName() << "\n" RESET
		<< "Grade To Signed: " GREEN ITALI BOLD << obj_form.getGradeSigned() << "\n" RESET
		<< "Grade to Execute: " GREEN ITALI BOLD << obj_form.getGradeExecute() << "\n" RESET
		<< "Signed: " GREEN ITALI BOLD << obj_form.getIsSignedText() << "\n" RESET;
	return (os);
}
