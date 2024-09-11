/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 13:56:01 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include "Color.hpp"

#define ANIMAL "\033[32mANIMAL base\033[0m"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal & origin);
		Animal &operator=(const Animal & origin);
		virtual			~Animal();
		virtual void	makeSound() const;
		std::string	getType() const;
};

#endif