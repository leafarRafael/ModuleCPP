/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 15:03:52 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include "Color.hpp"

#define AANIMAL "\033[32mAANIMAL abstract\033[0m"

class AAnimal
{
	protected:
		std::string _type;
		AAnimal();
		AAnimal(const AAnimal & origin);
		AAnimal &operator=(const AAnimal & origin);
	public:
		virtual			~AAnimal();
		virtual void	makeSound() const = 0;
		std::string	getType() const;
};

#endif