/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test07.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 09:47:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "test.hpp"

int test07(){
	msgTest(" Teste 'WrongAnimal = WrongCat' and 'Animal = Cat' ");

	msg_("Instances WrongAnimal and WrongCat class:", 1);
	msg_("WrongAnimal* WAnimal_WCat = new WrongCat();", 2);
	WrongAnimal* WAnimal_WCat = new WrongCat();
	msg_("WrongCat* WCat = new WrongCat();", 2);
	WrongCat* WCat = new WrongCat();

	msg_("Instances Animal and Cat class:", 1);
	msg_("Cat *CCat = new Cat();", 2);
	Cat *CCat = new Cat();
	msg_("Animal *Animal_Cat = new Cat();", 2);
	Animal *Animal_Cat = new Cat();

	msg_("Method execution getType and makeSound() by WrongAnimal and WrongCat:", 1);
	std::cout << "Object 'WAnimal_WCat' is " << WAnimal_WCat->getType() << '\n';
	WAnimal_WCat->makeSound();
	std::cout << '\n';
	std::cout << "Object 'WCat' is " << WCat->getType() << '\n';
	WCat->makeSound();

	msg_("Method execution getType and makeSound() by Animal and Cat:", 1);
	std::cout << "Object 'Animal_Cat' is " << Animal_Cat->getType() << '\n';
	Animal_Cat->makeSound();
	std::cout << "Object 'CCat' is " << CCat->getType() << '\n';
	CCat->makeSound();

	msg_("Destructor Objcts", 1);
	msg_("delete WAnimal_WCat;", 2);
	delete WAnimal_WCat;
	msg_("delete WCat;", 2);
	delete WCat;
	msg_("delete Animal_Cat;", 2);
	delete Animal_Cat;
	msg_("delete CCat;", 2);
	delete CCat;;
	return (0);
}


