/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:47:51 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 08:51:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBEERYCREATIONFORM_HPP
#define SHRUBEERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

#define SIGN_SHRUBEERY 145
#define EXEC_SHRUBEERY 137

class ShrubberyCreationForm:public AForm{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj_shrubbery);
		ShrubberyCreationForm&operator=(const ShrubberyCreationForm &obj_shrubbery);
		std::string	getTarget() const ;
		void	howToRun() const;

		class OpenFileException : public AFormException{
			public:
				virtual const char *what() const throw();	
		};

};

#define TREE "\
        &&& &&  & &&           &&& &&  & && \n\
    && &\\/&\\|& ()|/ @, &&   && &\\/&\\|& ()|/ @, && \n\
    &\\/(/&/&||/& /_/)&_&/   &\\/(/&/&||/& /_/)&_&/ \n\
&() &\\/&|()|/&\\/ '%\" & ()&() &\\/&|()|/&\\/ '%\" & () \n\
    &_\\/_&&_/\\/&    &__/_&     &_\\/_&&_/\\/&    &__/_& \n\
&&   && & &| &| /& & % ()& /&& &&   && & &| &| /& & % ()& /&& \n\
    ()&_---()&\\&\\/%&_& &&&     ()&_---()&\\&\\/%&_& &&& \n\
        &&     \\|||              &&     \\|||  \n\
                |||                     |||  \n\
                |||                     |||  \n\
                |||                     |||  \n\
          , -=-~  .-^- _           , -=-~  .-^- _ "


#endif