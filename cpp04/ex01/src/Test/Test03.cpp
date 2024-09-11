/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test03.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 09:31:35 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "test.hpp"

int test03(){
	msgTest(" Testes mothods orthodox WrongAnimal class ");

	msg_("Instances of the WrongAnimal class:", 1);
	
	msg_("WrongAnimal* defultConstr = new WrongAnimal();", 2);
	WrongAnimal* defultConstr = new WrongAnimal();
	msg_("WrongAnimal* copyConstr = new WrongAnimal(*defultConstr);", 2);
	WrongAnimal* copyConstr = new WrongAnimal(*defultConstr);
	msg_("WrongAnimal* copyAssignment  = new WrongAnimal();", 2);
	WrongAnimal* copyAssignment  = new WrongAnimal();
	msg_("*copyAssignment = *copyConstr;", 2);
	*copyAssignment = *copyConstr;


	msg_("Method execution getTyoe() and makeSound():", 1);

	std::cout << "Object 'defultConstr' is " << defultConstr->getType() << '\n';
	defultConstr->makeSound();


	msg_("Destructor WrongAnimal class", 1);
	
	msg_("delete defultConstr;", 2);
	delete defultConstr;
	msg_("delete copyConstr;", 2);
	delete copyConstr;
	msg_("delete copyAssignment;", 2);
	delete copyAssignment;
	msg_("\n", 2);
	return (0);
}