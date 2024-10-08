/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:47:51 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 08:55:11 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

#define SIGN_PARDON 72
#define EXEC_PARDON 45

class PresidentialPardonForm:public AForm{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &presidential);
		PresidentialPardonForm&operator=(const PresidentialPardonForm &presidential);
		std::string	getTarget() const ;
		void	howToRun() const;

		class PardonException:public AFormException{
			public:
				virtual const char *what() const throw();	
		};
};

#endif