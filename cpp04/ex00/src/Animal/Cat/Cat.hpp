/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/09 17:48:08 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include "Animal.hpp"
#define CAT "\033[31mCat\033[0m"

#define ASCII_CAT \
" /\\_/\\ \n"\
"( o.o )  \n"\
" > ^ <    \033[31mM\033[32mE\033[33mO\033[35mW\033[36mW\033[37mWW\033[0m"

class Cat : public Animal
{
	public:
		~Cat();
		Cat();
		Cat(const Cat & origin);
		Cat&operator=(const Cat & origin);
		void	makeSound() const;
		std::string	getType() const;
};

#endif