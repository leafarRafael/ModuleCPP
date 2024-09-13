/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test08.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 17:15:58 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int test08(){
	msgTest(" Test Deep Copy Cat");
	
	msg_("Animal *array;", 1);
	msg_("Cat *cat = new Cat();", 2);
	Cat *cat = new Cat();
	msg_("Cat *ptr;", 2);
	Cat *ptr = new Cat();
	msg_("*ptr = *cat;", 2);
	*ptr = *cat;

	msg_("Adrr to Brain ", 1);
	msg_("std::cout << ptr->getBrain();", 2);
	std::cout << ptr->getBrain() << '\n';
	msg_("std::cout << cat->getBrain()", 2);
	std::cout << cat->getBrain() << '\n';


	delete cat;
	delete ptr;
	return (0);
}
