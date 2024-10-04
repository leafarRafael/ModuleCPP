/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/04 18:13:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestManager.hpp"
#include <string>
#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <sstream>
#include <cctype>
#include <cstdlib>

void options(std::string &option);
void specfic();

int	main()
{
	std::string	option;

	for(;;)
	{
		options(option);
		if (option.length() == 1 && std::toupper(option.c_str()[0]) == 'E')
			break ;
		else if (option.length() == 1 && std::toupper(option.c_str()[0]) == 'A')
			runAllTest();
		else if (option.length() == 1 && std::toupper(option.c_str()[0]) == 'X')
			specfic();
		else
			std::cout << RED "Option not found\n" RESET ;
		Debug::msg(1, "   Press any key to proceed   ");
		std::getline(std::cin, option);
		system("clear");
			
	}
	return 0;
}

void options(std::string &option)
{
	std::string msg[6] = {
		ITALI SUBLI BOLD MAGENTA "   Options for running tests:\n\n",
		ITALI SUBLI BOLD MAGENTA "Type [X] to choose a specific test\n",
		ITALI SUBLI BOLD MAGENTA "Type [A] to run all tests\n",
		ITALI SUBLI BOLD MAGENTA "Type [E] to exit\n",
		ITALI SUBLI BOLD MAGENTA "Digite:",
	};
	for (int i = 0; i < 6; i++)
		Debug::msg(2, msg[i].c_str(), " ");
	std::getline(std::cin, option);
	system("clear");
}

void specfic()
{
	std::string			nbr;
	std::stringstream	m;
	int					i = 0;

	m << NBR_TEST -1;
	std::cout << "Digite nbr teste: ";
	std::getline(std::cin, nbr);
	if (nbr.empty())
	{
		Debug::msg(3, RED "Choose between 0 and ", m.str().c_str(), "\n" RESET);
		return ;
	}
	for (int x = 0; x < static_cast<int>(nbr.length()); x++)
	{
		if (!std::isdigit(nbr.c_str()[x]))
		{
			Debug::msg(3, RED "Choose between 0 and ", m.str().c_str(), "\n" RESET);
			return ;
		}
	}
	std::stringstream(nbr) >> i;
	if (i >= 0 && i < NBR_TEST)
		runSpecificTest(i);
	else
		Debug::msg(3, RED "Choose between 0 and ", m.str().c_str(), "\n" RESET);
}