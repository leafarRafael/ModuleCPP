/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 13:55:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include "Collor.hpp"

#define WRONG_ANIMAL "\033[33mWrong Animal\033[0m"

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal & origin);
		WrongAnimal &operator=(const WrongAnimal & origin);
		virtual ~WrongAnimal();
		void	makeSound() const;
		std::string	getType() const;

};

#endif