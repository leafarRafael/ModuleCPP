/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:29:01 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 16:14:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

#define ICE "\033[36mice\033[0m"

class ICharacter;

class Ice:public AMateria
{
	public:
		~Ice();
		Ice();
		Ice(const Ice & origin);
		Ice&operator=(const Ice & origin);

		AMateria* clone() const;
		void use(ICharacter& target);
};


#endif