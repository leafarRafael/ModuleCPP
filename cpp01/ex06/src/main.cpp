/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/19 15:04:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int	damn_harl(char *str);

int main(int argc, char **argv)
{
	Harl		harl;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return (1);
	}
	harl.complain(std::string(argv[1]));
	return 0;
}

