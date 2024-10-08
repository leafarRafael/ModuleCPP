/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/05 18:20:48 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "TestManager.hpp"
#include <unistd.h>

int (*select_test(int i))();
void	generalStatus(int total);

int	runAllTest(){
	int total = 0;
	if (NBR_TEST == 0)
		runSpecificTest(0);
	else
	{
		int respost = 0;
		for(int i = 0; i < NBR_TEST; i++)
		{
			respost = (*select_test(i))();
			if (respost == 0)
			{
				total++;
				Debug::msg(2, "STATUS ", BLUE "[OK]" RESET);
			}
			else
				Debug::msg(2, "STATUS ", RED "[ERROR]" RESET);
			Debug::msg(1, ITALI SUBLI BOLD MAGENTA "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			std::cout << std::endl;
			sleep(1);
		}
		generalStatus(total);
	}
	return 0;
}

int	runSpecificTest(int value){
	int respost = 0;

	respost = (*select_test(value))();
	if (respost == 0)
		Debug::msg(2, "STATUS ", BLUE "[OK]" RESET);
	else
		Debug::msg(2, "STATUS ", RED "[ERROR]" RESET);
	Debug::msg(1, ITALI SUBLI BOLD MAGENTA "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	std::cout << std::endl;
	return 0;
}

int (*select_test(int i))(){
	int	(*function[20])() = {
		test00,
		test01,
		test02,
		test03,
		test04,
		test05,
		test06,
		test07,
		test08,
		test09,
		test10,
		test11,
		};
	return (function[i]);
}

void	generalStatus(int total){
	std::cout << std::endl;
	std::cout << BLUE << ITALI SUBLI BOLD MAGENTA "  General status ;" RESET << '\n';
	std::cout << BLUE << "Number of tests performed: " << '[' << YELLOW << NBR_TEST << RESET BLUE "]" << '\n';
	std::cout << BLUE << "Successful tests:          " << '[' << GREEN << total << RESET BLUE "]" << '\n';
	std::cout << BLUE << "Failed tests:              " << '[' << RED << total - NBR_TEST << RESET BLUE "]" << '\n';
	Debug::msg(1, ITALI SUBLI BOLD MAGENTA "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}