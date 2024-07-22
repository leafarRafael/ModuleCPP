/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:00:04 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/19 15:08:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{};

Harl::~Harl()
{};

void Harl::debug()
{
	std::cout << "[ " << DEBUG << " ]\n"
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
};

void Harl::info()
{
	std::cout << "[ " << INFO << " ]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
};

void Harl::warning()
{
	std::cout << "[ " << WARNING << " ]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you started working here since last month.\n";
};

void Harl::error()
{
	std::cout << "[ "  << ERROR << " ]\n"
		<< "This is unacceptable! I want to speak to the manager now.\n";
};

static int	damn_harl(std::string str);

void Harl::complain(std::string input)
{
	int			i;

	i = damn_harl(input);
	switch (i)
	{
		case 0:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break ;
		case 1:
			debug();
		case 2:
			info();
		case 3:
			warning();
		case 4:
			error();
	}
};

static int	damn_harl(std::string str)
{
	std::string badHarl(str);
	t_input		input[5] = {{DEBUG, 1},
							{INFO, 2},
							{WARNING, 3},
							{ERROR, 4}};

	for (int i = 0; i < 4; i++)
	{
		if (input[i].input == badHarl)
			return (input[i].index);
	}
	return (0);
}
