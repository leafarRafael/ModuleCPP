/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/31 10:45:58 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *horde;

	horde = zombieHorde(8, "HORDA");
	for (int i = 0; i < 8; i++)
	{
		std::cout << "Zombie number [" << i << "] ";
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
