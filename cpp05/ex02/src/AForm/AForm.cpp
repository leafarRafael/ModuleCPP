/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:47:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 09:38:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "AForm.hpp"
#include "Debug.hpp"
#include "Bureaucrat.hpp"

//************************************************************************************
//********************************* Member function **********************************
//************************************************************************************
void	AForm::beSigned(Bureaucrat &burr){
	if (burr.getGrade() > this->_grade_signed)
		throw AForm::GradeTooLowException();	
	this->_is_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const{
	int	exec = this->getGradeExecute();

	if (!this->getIsSigned())
	{
		throw AForm::FormNotYetSignedException();
		return ;
	}
	if (executor.getGrade() > exec){
		throw AForm::GradeTooLowException();
		return ;
	}
	this->howToRun();
}

void	AForm::howToRun() const {
	Debug::msg(1, ITALI SUBLI BOLD RED "how to Run needs implement in children.\n");
}

//************************************************************************************
//********************************* Orthodox Canonical class form ********************
//************************************************************************************
AForm::~AForm(){
	Debug::msgOrthodox(1, BLUE "Destructor Form is called.\n");
}

AForm::AForm():_name("DefaultForm"), _grade_signed(150), _grade_execute(150), _is_signed(false){
	Debug::msgOrthodox(1, BLUE "Constructor default Form is called.\n");	
}

AForm::AForm(std::string name, int grade_signed, int grade_execute):
_name(name), _grade_signed(grade_signed), _grade_execute(grade_execute), _is_signed(false)
{
	Debug::msgOrthodox(1, BLUE "Constructor Form with parameters is called.\n");
	if (grade_signed < 1 || grade_execute < 1)
		throw AForm::GradeTooHighException();
	if (grade_signed > 150 || grade_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &obj_form):
_name(obj_form.getName()), _grade_signed(obj_form.getGradeSigned()),
_grade_execute(obj_form.getGradeExecute()), _is_signed(false){
	Debug::msgOrthodox(1, BLUE "Copy constructor Form is called.\n");	
}

AForm &AForm::operator=(const AForm &obj_form){
	if(this != &obj_form)
		this->_is_signed = obj_form.getIsSigned();
	Debug::msgOrthodox(1, BLUE "Copy assignment Form is called \n");
	return *this;
}

//************************************************************************************
//********************************* Methods geters ***********************************
//************************************************************************************
const std::string	&AForm::getName() const{
	return (_name);	
}

int					AForm::getGradeSigned() const{
	return (_grade_signed);
}

int					AForm::getGradeExecute() const{
	return (_grade_execute);
}

bool				AForm::getIsSigned() const{
	return  (_is_signed);
}

std::string			AForm::getIsSignedText() const{
	if (_is_signed)
		return (BLUE ITALI BOLD "Yes" RESET);
	return (RED ITALI BOLD "Not" RESET);	
}

//************************************************************************************
//********************************* Overload exception *******************************
//************************************************************************************
const char *AForm::AFormException::what() const throw(){
	return (RED SUBLI ITALI "FormException default is called.\n" RESET);
}

const char *AForm::GradeTooHighException::what() const throw(){
	return (RED SUBLI ITALI "Grade too high exception.\n " RESET); 
}

const char *AForm::GradeTooLowException::what() const throw(){
	return (RED SUBLI ITALI "Grade too low exception.\n" RESET);
}

const char *AForm::FormNotYetSignedException::what() const throw(){
	return (RED SUBLI ITALI "Form not yet signed.\n" RESET);
}

//************************************************************************************
//********************************* Overload of the insertion («) ********************
//************************************************************************************
std::ostream &operator<<(std::ostream &os, const AForm &obj_form){
	os << "Name: " GREEN ITALI BOLD << obj_form.getName() << "\n" RESET
		<< "Grade To Signed: " GREEN ITALI BOLD << obj_form.getGradeSigned() << "\n" RESET
		<< "Grade to Execute: " GREEN ITALI BOLD << obj_form.getGradeExecute() << "\n" RESET
		<< "Signed: " GREEN ITALI BOLD << obj_form.getIsSignedText() << "\n" RESET;
	return (os);
}
