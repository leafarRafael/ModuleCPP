/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test04.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 18:04:41 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static void allocCat(AAnimal **array);
static void allocDog(AAnimal **array);
static void destroy(AAnimal **array);

int	max_array = 4;

int test04(){
	msgTest(" Test Array AAnimal Objects ");
	
	msg_("AAnimal *array;", 1);
	AAnimal **array = new AAnimal*[max_array];
	allocCat(array);
	allocDog(array);
	destroy(array);
	return (0);
}

static void allocCat(AAnimal **array)
{
	for (int i = 0; i < max_array / 2; i++)
	{
		std::cout << "array" << '[' << i << ']' << " Instance object Cat:\n";
		array[i] = new Cat();
		std::cout << '\n';
	}
}

static void allocDog(AAnimal **array)
{
	for (int i = max_array / 2; i < max_array; i++)
	{
		std::cout << "array" << '[' << i << ']' << " Instance object Dog:\n";
		array[i] = new Dog();
		std::cout << '\n';
	}
}

static void destroy(AAnimal **array)
{
	for (int i = 0; i < max_array; i++)
		delete array[i];
	delete[] array;
}