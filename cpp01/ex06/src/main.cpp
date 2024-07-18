/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/18 16:00:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int	damn_harl(char *str);

int main(int argc, char **argv)
{
	Harl		harl;
	int			i;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return (1);
	}
	i = damn_harl(argv[1]);
	switch (i)
	{
		case 0 :
			std::cout << "[ Probably complaining about insignificant problems ]\n";
		case 1 :
			harl.complain(i);
			break;
		case 2 :
			harl.complain(i);
			break;
		case 3 :
			harl.complain(i);
			break;
		case 4 :
			harl.complain(i);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}

	return 0;
}

int	damn_harl(char *str)
{
	std::string badHarl(str);
	t_input		input[4] = {{DEBUG, 0},
							{INFO, 1},
							{WARNING, 2},
							{ERROR, 3}};

	for (int i = 0; i < 4; i++)
	{
		if (input[i].input == badHarl)
			return (input[i].index);
	}
	return (0);
}
