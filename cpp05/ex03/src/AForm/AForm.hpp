/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:36:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/07 15:38:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <ostream>
#include <string>

class Bureaucrat;

class AForm{
	private:
		const std::string	_name;
		const int			_grade_signed;
		const int			_grade_execute;
		bool				_is_signed;

	public:
		virtual ~AForm();
		AForm();
		AForm(std::string name, int grade_signed, int grade_execute);
		AForm(const AForm &obj_form);
		AForm&operator=(const AForm &obj_form);

		virtual void		execute(Bureaucrat const & executor) const;
		virtual void		howToRun() const;
		const std::string	&getName() const;
		int					getGradeSigned() const;
		int					getGradeExecute() const;
		bool				getIsSigned() const;
		std::string			getIsSignedText() const;
		void				beSigned(Bureaucrat &burr);

		class AFormException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public AFormException{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public AFormException{
			public:
				virtual const char *what() const throw();
		};
		class FormNotYetSignedException : public AFormException{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &obj_form);

#endif