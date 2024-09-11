/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/09 19:54:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "test.hpp"

int	test00()
{
	msgTest(" Testes mothods orthodox Animal class ");
	msg_("Instances of the animal class:", 1);

	msg_("Animal* defultConstr = new Animal();", 2);
	Animal* defultConstr = new Animal();
	msg_("Animal* copyConstr = new Animal(*defultConstr);", 2);
	Animal* copyConstr = new Animal(*defultConstr);
	msg_("Animal* copyAssignment  = new Animal();", 2);
	Animal* copyAssignment  = new Animal();
	msg_("*copyAssignment = *copyConstr;", 2);
	*copyAssignment = *copyConstr;
	msg_("Method execution makeSound():", 1);
	msg_("defultConstr->makeSound();", 2);
	defultConstr->makeSound();
	msg_("Destructor Animal class", 1);
	msg_("delete defultConstr;", 2);
	delete defultConstr;
	msg_("delete copyConstr;", 2);
	delete copyConstr;
	msg_("delete copyAssignment;", 2);
	delete copyAssignment;
	msg_("\n", 2);
	return (0);
}