/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test07.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 16:22:39 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "test.hpp"

static void allocCat(Animal **array);
static void allocDog(Animal **array);
static void destroy(Animal **array);

int	max_array = 4;

int test07(){
	msgTest(" Test Array Animal Objects ");
	
	msg_("Animal *array;", 1);
	Animal **array = new Animal*[max_array];
	allocCat(array);
	allocDog(array);
	destroy(array);
	return (0);
}

static void allocCat(Animal **array)
{
	for (int i = 0; i < max_array / 2; i++)
		array[i] = new Cat();
}

static void allocDog(Animal **array)
{
	for (int i = max_array / 2; i < max_array; i++)
		array[i] = new Dog();
}

static void destroy(Animal **array)
{
	for (int i = 0; i < max_array; i++)
		delete array[i];
	delete[] array;
}