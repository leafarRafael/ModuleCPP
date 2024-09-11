/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 15:09:27 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int test01(){
	msgTest(" Testes mothods orthodox Cat class ");
	msg_("Instances of the Cat class:", 1);
	msg_("AAnimal* tom = new Cat();", 2);
	AAnimal* tom = new Cat();
	msg_("Cat* garfield = new Cat(static_cast<Cat&>(*tom));", 2);
	Cat* garfield = new Cat(static_cast<Cat&>(*tom));
	msg_("Cat* felix  = new Cat();", 2);
	Cat* felix  = new Cat();
	msg_("*felix = static_cast<Cat&>(*tom);", 2);
	*felix = static_cast<Cat&>(*tom);
	
	msg_("Method execution and makeSound():", 1);
	std::cout << tom->getType() << " object tom" << '\n';
	tom->makeSound();
	std::cout << garfield->getType() << " object garfield" << '\n';
	garfield->makeSound();
	std::cout << felix->getType()<< " object felix" << '\n';
	felix->makeSound();

	msg_("Destructor class", 1);
	msg_("delete tom;", 2);
	delete tom;
	msg_("delete garfield;", 2);
	delete garfield;
	msg_("delete felix;", 2);
	delete felix;
	msg_("\n", 2);
	return (0);
}