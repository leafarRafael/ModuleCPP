/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 07:44:19 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 08:18:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

#define AMATERIA "\033[35mAMateria\033[0m"

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria & origin);
		AMateria&operator=(const AMateria & origin);

		std::string const & getType() const;
		virtual ~AMateria();
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif