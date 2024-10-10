/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/10 08:42:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestManager.hpp"
#include "UnitTest.hpp"
#include "Color.hpp"
#include "Debug.hpp"
#include <unistd.h>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>

void		testName(std::string test, std::string color);
std::string formateStatus(int value, std::string msg, std::string color);
std::string	testNBR(int value);
std::string	getInput();
int			getOptions(std::string option);

void	TestManager::options(){
	std::string	option;
	int			value = 0;

	for(;;){
		menuOptions(option);
		value = getOptions(option);
		switch (value){
			case 0:
				return ;
			case 1:
				runAllTest();
				break;
			case 2: 
				specific();
				break;
			case 3: 
				std::cout << RED "Option not found\n" RESET ;
				break ;
			default:
				break;
		}
		Debug::msg(1, "\n   press any key to continue   ");
		option = getInput();
	}
}

int	TestManager::runAllTest(){
	int	total = 0, respost = 0;
	int	nbrTests = UnitTest::getTotalTest();

	for(int i = 0; i < nbrTests; i++)
	{
		testName(testNBR(i), MAGENTA);
		respost = (*UnitTest::select_test(i))();
		if (respost == 0){
			total++;
			Debug::msg(2, MAGENTA "STATUS: ", BLUE "[OK]" RESET);
		}
		else
			Debug::msg(2, MAGENTA "STATUS: ", RED "[ERROR]" RESET);
		std::cout << std::endl;
		sleep(1);
	}
	generalStatus(total, nbrTests);
	return 0;
}

int	TestManager::runSpecificTest(int value){
	testName(testNBR(value), MAGENTA);
	int respost = (*UnitTest::select_test(value))();
	if (respost == 0)
		Debug::msg(2, "STATUS ", BLUE "[OK]" RESET);
	else
		Debug::msg(2, "STATUS ", RED "[ERROR]" RESET);
	std::cout << std::endl;
	return 0;
}

void TestManager::menuOptions(std::string &option)
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
	option = getInput();
}

void	testName(std::string test, std::string color){
	std::cout << color << SUBLI << ITALI;
	std::cout << std::setfill(' ') << std::setw(60) << test << RESET "\n";
}

std::string testNBR(int value){
	std::string			testNumber("Test [");
	std::stringstream	strNumber;
	strNumber << value;
	testNumber += strNumber.str(); 
	testNumber.append("]");
	return testNumber;
}

std::string	getInput(){
	std::string	input;
	std::getline(std::cin, input);
	system("clear");
	return input;
}

int		getOptions(std::string option){
	char	valid[3] = {'E', 'A', 'X'};

	if (option.length() != 1)
		return 3;
	for (int i = 0; i < 3; i++){
		if (std::toupper(option[0]) == valid[i])
			return i;
	}
	return (3);
}


void	TestManager::generalStatus(int successTest, int totalTests){
	int	failedTests = totalTests - successTest;
	std::string msg[4] = {
		ITALI SUBLI BOLD MAGENTA "               General status:" RESET "\n",
		formateStatus(totalTests, "Number of tests performed: [", BLUE),
		formateStatus(successTest, "Successful:                [", GREEN),
		formateStatus(failedTests, "Failed:                    [", RED),
	};
	for (int i = 0; i < 4;i++)
		std::cout << msg[i];
}

void TestManager::specific(){
	int	nbrTests = UnitTest::getTotalTest(), i = 0;
	std::string			nbr;
	std::stringstream	m;

	m << nbrTests -1;
	Debug::msg(1, MAGENTA ITALI SUBLI BOLD "Select the test: " RESET);
	nbr = getInput();
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
	if (i >= 0 && i < nbrTests)
		runSpecificTest(i);
	else
		Debug::msg(3, RED "Choose between 0 and ", m.str().c_str(), "\n" RESET);
}

std::string formateStatus(int value, std::string msg, std::string color){
	
	std::stringstream	intToStr;
	std::string	formatting(ITALI SUBLI BOLD MAGENTA);
	std::string formated;
	intToStr << value;

	formated += formatting;
	formated += msg;
	formated += RESET;
	formated += color;
	formated += intToStr.str();
	formated += formatting;
	formated += "]\n";
	return formated;
}