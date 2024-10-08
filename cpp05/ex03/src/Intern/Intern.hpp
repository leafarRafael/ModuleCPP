/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:47:15 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 12:51:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <ostream>

class AForm;

#define PRESIDENTIAL 0
#define ROBOTOMY 1
#define SHRUBBERY 2

struct PtrForm{
	std::string form;
	AForm *(*function)(std::string _target);
};

class Intern{
	private:
		PtrForm *_allForm;
		static AForm	*presidentialPardonForm(std::string _target);
		static AForm	*robotomyRequestForm(std::string _target);
		static AForm	*shrubberyCreationForm(std::string _target);
		static void		cpyAllForm(PtrForm *dest, PtrForm *origin);
		PtrForm*	getAllForm() const;
	
	public:
		~Intern();
		Intern();
		Intern(Intern const &inter);
		Intern&operator=(Intern const &inter);
		AForm *makeForm(std::string nameForm, std::string targeForm);
};


#endif