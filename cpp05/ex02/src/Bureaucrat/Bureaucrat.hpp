/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:47:15 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 10:04:06 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
class AForm;

class Bureaucrat{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
		~Bureaucrat();
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &burr);
		Bureaucrat&operator=(Bureaucrat const &burr);

		const std::string	&getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &obj_form);
		void				executeForm(AForm const & form);

		class BureaucratException:public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException:public BureaucratException{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException:public BureaucratException{
			public:
				virtual const char *what() const throw();
		};
		class UnsignedForm:public BureaucratException{
			public:
				virtual const char *what() const throw();
		};
		class FormNoTExecuted:public BureaucratException{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &burr);

#endif