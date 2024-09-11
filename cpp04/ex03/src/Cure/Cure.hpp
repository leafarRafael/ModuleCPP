/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:22:32 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 16:15:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

#define CURE "\033[32mcure\033[0m"

class ICharacter;

class Cure:public AMateria
{
	public:
		~Cure();
		Cure();
		Cure(const Cure & origin);
		Cure&operator=(const Cure & origin);
	
		AMateria* clone() const;
		void use(ICharacter& target);
};


#endif
