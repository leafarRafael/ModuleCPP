/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 17:31:34 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include "AAnimal.hpp"
#include "Color.hpp"
#include "Brain.hpp"

#define DOG "\033[35mDog\033[0m"
#define DOG_SOUND "\033[31mA\033[32mU\033[33m-\033[35mA\033[36mU\033[37mUUU\033[0m"
#define DOG_ASCII \
"╱▔╲╱▔▔▔▔╲╱▔╲\n" \
"▏┊╱┊┊▂┊▂┊╲┊▕\n" \
"╲╳▏┊┏▅┐ ┏▅┐╳╱\n" \
"┊┊▏╭╰━╯╰━┻━━╮\n" \
"╱▔▏▕┊┊┊┊┊▕▔▔▔▏      / - - - - - - - \\ \n"\
"▏┊▏▕┊┊┊┊┊┊╲▂╱▏  ~<   stop the pigeon | \n"\
"▏┊▏┊╲┊┊┊▕╲┊┃▕╱▏     \\ - - - - - - - /\n" \
"▏┊╲┊┊▔▔▔▔▔▔▔▔▔▏\n" \
"▏┊▏╲▂▂▂▂▂▂▂▂▂╱\n" \
"▏┊▏┊┊┊┊┊┊┊┊▕\n" \
"▏┊▏┊┊┊┊┊┊┊┊▕\n"

class Dog : public AAnimal
{
	private:
		Brain *_brain;
	
	public:
		~Dog();
		Dog();
		Dog(const Dog & origin);
		Dog&operator=(const Dog & origin);
		void	makeSound() const;		
		std::string getType();
		Brain * getBrain() const;
};

#endif
