/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test05.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 09:39:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "test.hpp"


int test05(){
 
	msgTest(" Teste subject WrongAnimal WrongCat ");
	const WrongAnimal* animalWrong = new WrongAnimal();
	const WrongAnimal* catWrong = new WrongCat();
	std::cout << catWrong->getType() << " " << std::endl;
	catWrong->makeSound();
 	animalWrong->makeSound();
	delete animalWrong;
	delete catWrong;
	return (0);
}
