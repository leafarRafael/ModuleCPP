/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test05.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 18:13:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int test05(){
	msgTest(" Test Deep Copy Cat ");
	
	msg_("Animal *array;", 1);
	msg_("Cat *cat = new Cat();", 2);
	Cat *cat = new Cat();
	msg_("Cat *ptr;", 2);
	Cat *ptr = new Cat();
	msg_("*ptr = *cat;", 2);
	*ptr = *cat;

	std::cout << "addr ptr->getBrain(): " << ptr->getBrain() << '\n';
	std::cout << "addr cat->getBrain(): " << cat->getBrain() << '\n';

	delete cat;
	delete ptr;
	return (0);
}
