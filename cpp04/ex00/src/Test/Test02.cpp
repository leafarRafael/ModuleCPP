/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test02.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 09:27:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "test.hpp"

int test02(){
	msgTest(" Testes mothods orthodox Dog class ");
	msg_("Instances of the Dob class:", 1);

	msg_("Animal* ScoobyDoo = new Animal();", 2);
	Animal* ScoobyDoo = new Animal();
	msg_("Dog* snoopy = new Dog(static_cast<Dog&>(*ScoobyDoo));", 2);
	Dog* snoopy = new Dog(static_cast<Dog&>(*ScoobyDoo));
	msg_("Animal* mutley  = new Dog();", 2);
	Animal* mutley  = new Dog();
	msg_("*mutley = *ScoobyDoo;", 2);
	*mutley = *snoopy;
	
	msg_("Method execution and makeSound():", 1);
	std::cout << "Object ScoobyDoo is " << ScoobyDoo->getType() << '\n';
	ScoobyDoo->makeSound();
	std::cout << "\n";
	std::cout << "Object snoopy is " << snoopy->getType() << '\n';
	snoopy->makeSound();
	std::cout << "Object mutley is " << mutley->getType() << '\n';
	mutley->makeSound();

	msg_("Destructor Animal class", 1);
	msg_("delete ScoobyDoo;", 2);
	delete ScoobyDoo;
	msg_("delete snoopy;", 2);
	delete snoopy;
	msg_("delete mutley;", 2);
	delete mutley;
	msg_("\n", 2);
	return (0);
}