/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/09 18:40:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <string>
#include "WrongAnimal.hpp"

#define WRONG_CAT "\033[31mWrongCat\033[0m"

#define ASCII_WRONG_CAT \
" _._     _,-'\"\"`-._\n" \
"(,-.`._,'(       |\\`-/|\n" \
"    `-.-' \\ )-`( , o o)   \033[31mM\033[32mE\033[33mO\033[35mW\033[36mW\033[37mWW\033[0m\n" \
"          `-    \\`_`\"'- \n"

class WrongCat : public WrongAnimal
{
	public:
		~WrongCat();
		WrongCat();
		WrongCat(const WrongCat & origin);
		WrongCat&operator=(const WrongCat & origin);
		void	makeSound() const;
		std::string	getType() const;
};

#endif