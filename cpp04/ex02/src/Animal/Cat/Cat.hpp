/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 17:29:55 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

#define CAT "\033[31mCat\033[0m"
#define ASCII_CAT \
" _._     _,-'\"\"`-._\n" \
"(,-.`._,'(       |\\`-/|\n" \
"    `-.-' \\ )-`( , o o)   \033[31mM\033[32mE\033[33mO\033[35mW\033[36mW\033[37mWW\033[0m\n" \
"          `-    \\`_`\"'- \n"

class Cat : public AAnimal
{
	private:
		Brain *_brain;

	public:
		~Cat();
		Cat();
		Cat(const Cat & origin);
		Cat&operator=(const Cat & origin);
		void	makeSound() const;
		Brain * getBrain() const;
		std::string	getType() const;
};

#endif