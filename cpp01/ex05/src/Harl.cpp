/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:00:04 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/27 17:16:55 by rbutzke          ###   ########.fr       */
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
	std::cout << "[ " << DEBUG << " ]"
		<< DEBUG_MSG << '\n';
};

void Harl::info()
{
	std::cout << "[ " << INFO << " ]"
		<< INFO_MSG << '\n';
};

void Harl::warning()
{
	std::cout << "[ "  << WARNING << " ]"
		<< WARNING_MSG << '\n';
};

void Harl::error()
{
	std::cout << "[ "  << ERROR << " ]"
		<< ERROR_MSG << '\n';
};

void Harl::complain(std::string level)
{
	t_pointer	ptr[4] = {
		{DEBUG, &Harl::debug},
		{INFO, &Harl::info},
		{WARNING, &Harl::warning},
		{ERROR, &Harl::error}};

	for (int i = 0; i < 4; i++)
	{
		if (level == ptr[i].input)
			(this->*(ptr[i].function))();
	}
};

