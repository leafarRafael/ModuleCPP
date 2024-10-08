/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:36:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/07 10:35:07 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <ostream>
#include <string>

class Bureaucrat;

class Form{
	private:
		const std::string	_name;
		const int			_grade_signed;
		const int			_grade_execute;
		bool				_is_signed;

	public:
		~Form();
		Form();
		Form(std::string name, int grade_signed, int grade_execute);
		Form(const Form &obj_form);
		Form&operator=(const Form &obj_form);

		const std::string	&getName() const;
		int					getGradeSigned() const;
		int					getGradeExecute() const;
		bool				getIsSigned() const;
		std::string			getIsSignedText() const;
		void				beSigned(Bureaucrat &burr);

		class FormException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public FormException{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public FormException{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &obj_form);

#endif