/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test06.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 18:12:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int test06(){
	msgTest(" Test Deep Copy Dog ");
	
	msg_("Instance os Dog Class", 1);
	msg_("Dog *dog = new Dog();", 2);
	Dog *dog = new Dog();
	msg_("Dog *ptr = new Dog();", 2);
	Dog *ptr = new Dog();
	msg_("*ptr = *dog;", 2);
	*ptr = *dog;

	std::cout << "addr ptr->getBrain(): " << ptr->getBrain() << '\n';
	std::cout << "addr dog->getBrain(): " << dog->getBrain() << '\n';
	
	delete ptr;
	delete dog;
	return (0);
}
