/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:29:01 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 21:18:06 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

#define ICE "ice"

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