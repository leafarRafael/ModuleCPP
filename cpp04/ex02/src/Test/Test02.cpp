/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test02.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 15:05:18 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int test02(){
	msgTest(" Testes mothods orthodox Dog class ");
	msg_("Instances of the Dob class:", 1);

	msg_("Dog* ScoobyDoo = new Dog();", 2);
	Dog* ScoobyDoo = new Dog();
	msg_("Dog* snoopy = new Dog(static_cast<Dog&>(*ScoobyDoo));", 2);
	Dog* snoopy = new Dog(*ScoobyDoo);
	msg_("Dog* mutley  = new Dog();", 2);
	Dog* mutley  = new Dog();
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
