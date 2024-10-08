/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:47:51 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 08:55:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

#define SIGN_ROBOT 72
#define EXEC_ROBOT 45

class RobotomyRequestForm:public AForm{
	private:
		std::string _target;
		static int	_chance_robotization;

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &robotomy);
		RobotomyRequestForm&operator=(const RobotomyRequestForm &robotomy);
		std::string	getTarget() const ;
		void	howToRun() const;

		class RobotomyException:public AFormException{
			public:
				virtual const char *what() const throw();	
		};
};

#endif