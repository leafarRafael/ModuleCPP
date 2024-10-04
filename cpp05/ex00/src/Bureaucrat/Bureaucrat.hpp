/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:29:14 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/04 18:15:11 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureucrat{
	private:
		const std::string	_name;	
		int					_grade;

	public:
		~Bureucrat();
		Bureucrat();
		Bureucrat(std::string const name, int grade);
		Bureucrat(Bureucrat const &origin);
		Bureucrat &operator=(Bureucrat const  &origin);		
		const std::string	&getName() const;
		int					getGrade() const;
		void				increment();
		void				decrement();


	class GradeTooHighException : public std::exception{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream & os, const Bureucrat & burr);

#endif