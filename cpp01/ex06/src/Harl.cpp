/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:00:04 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/18 15:50:26 by rbutzke          ###   ########.fr       */
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

void Harl::complain(int i)
{
	t_pointer	ptr[4] = {
		{DEBUG, &Harl::debug},
		{INFO, &Harl::info},
		{WARNING, &Harl::warning},
		{ERROR, &Harl::error}};

	while (i < 4)
	{
		(this->*(ptr[i].function))();
		i++;
	}
};

