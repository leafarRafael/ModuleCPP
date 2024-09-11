/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test04.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 09:38:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "test.hpp"

static void testMakeSound(WrongCat* tom, WrongCat* garfield, WrongCat* frajola);
static void delPtr(WrongAnimal* tom, WrongAnimal* garfield, WrongAnimal* frajola);

int test04(){
	msgTest(" Testes mothods orthodox WrongCat class ");
	msg_("Instances of the WrongCat class:", 1);

	msg_("WrongCat* tom = new WrongCat();", 2);
	WrongCat* tom = new WrongCat();

	msg_("WrongCat* garfield = new WrongCat(*tom);", 2);
	WrongCat* garfield = new WrongCat(*tom);

	msg_("WrongCat* frajola  = new WrongCat();", 2);
	WrongCat* frajola  = new WrongCat();

	msg_("*frajola = *garfield;", 2);
	*frajola = *garfield;


	testMakeSound(tom, garfield, frajola);
	delPtr(tom, garfield, frajola);
	return (0);
}

static void testMakeSound(WrongCat* tom, WrongCat* garfield, WrongCat* frajola)
{
	msg_("Method execution getType and makeSound():", 1);
	std::cout << "Object 'tom' is " << tom->getType() << '\n';
	tom->makeSound();
	std::cout << "Object 'garfield' is " << garfield->getType() << '\n';
	garfield->makeSound();
	std::cout << "Object 'frajola' is " << frajola->getType() << '\n';
	frajola->makeSound();
}


static void delPtr(WrongAnimal* tom, WrongAnimal* garfield, WrongAnimal* frajola)
{
	msg_("Destructor Animal class", 1);
	msg_("delete tom;", 2);
	delete tom;
	msg_("delete garfield;", 2);
	delete garfield;
	msg_("delete frajola;", 2);
	delete frajola;
	msg_("\n", 2);
}
