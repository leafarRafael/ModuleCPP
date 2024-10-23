/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/19 15:53:24 by rbutzke          ###   ########.fr       */
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

void	TestManager::showOptions(){
	int			value = 0;

	for(;;){
		value = getOptionSelection();
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
		getInput();
	}
}

int	TestManager::runAllTest(){
	int	totalSuccess = 0;
	int	totalTests = UnitTest::getTotalTest();

	for(int i = 0; i < totalTests; i++)
	{
		displayTestName(formatTestName(i), MAGENTA);
		totalSuccess += displayUnitStatus((*UnitTest::select_test(i))());
		sleep(1);
	}
	displayTestStatus(totalSuccess, totalTests);
	return 0;
}

int	TestManager::runSpecificTest(int value){
	displayTestName(formatTestName(value), MAGENTA);
	displayUnitStatus((*UnitTest::select_test(value))());;
	return 0;
}

int		TestManager::getOptionSelection(){
	std::string	input;
	char		validOptions[3] = {'E', 'A', 'X'};
	
	displayOptions();
	input = getInput();
	if (input.length() != 1)
		return 3;
	for (int i = 0; i < 3; i++){
		if (std::toupper(input[0]) == validOptions[i])
			return i;
	}
	return (3);
}

void TestManager::displayOptions(){
	std::string msg[6] = 
	{
		ITALI SUBLI BOLD MAGENTA "   Options for running tests:\n\n",
		ITALI SUBLI BOLD MAGENTA " Type [X] to choose a specific test\n",
		ITALI SUBLI BOLD MAGENTA " Type [A] to run all tests\n",
		ITALI SUBLI BOLD MAGENTA " Type [E] to exit\n",
		ITALI SUBLI BOLD MAGENTA " Digite:",
	};
	for (int i = 0; i < 6; i++)
		Debug::msg(1, msg[i].c_str());
	Debug::msg(1, " ");
}

std::string	TestManager::getInput(){
	std::string		input;
	std::getline(std::cin, input);
	system("clear");
	return input;
}

void	TestManager::displayTestName(std::string test, std::string color){
	std::cout << color << SUBLI << ITALI;
	std::cout << std::setfill(' ') << std::setw(60) << test << RESET "\n";
}

std::string TestManager::formatTestName(int value){
	std::string			testNumber("Test [");
	std::stringstream	strNumber;
	strNumber << value;
	testNumber += strNumber.str(); 
	testNumber.append("]");
	return testNumber;
}

void	TestManager::displayTestStatus(int successTest, int totalTests){
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

std::string TestManager::formateStatus(int value, std::string msg, std::string color){
	
	std::stringstream	intToStr;
	std::string			formatting(ITALI SUBLI BOLD MAGENTA);
	std::string			formated;

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

int	TestManager::displayUnitStatus(int respost) {
	if (respost == 0)
	{
		Debug::msg(2, GREEN "STATUS ", BLUE "[OK]" RESET "\n");
		return (1);
	}
	Debug::msg(2, GREEN "STATUS ", RED "[ERROR]" RESET "\n");
	return (0);
}

void TestManager::specific(){
	int					testIndex = 0;
	std::string			input;
	std::stringstream	strNumberTests;

	strNumberTests << UnitTest::getTotalTest() -1;
	Debug::msg(1, MAGENTA ITALI SUBLI BOLD "Select the test:" RESET);
	Debug::msg(1, " ");
	input = getInput();
	if (validateTestSelection(input))
	{
		Debug::msg(3, RED "Choose between 0 and ", strNumberTests.str().c_str(), "\n" RESET);
		return ;
	}
	std::stringstream(input) >> testIndex;
	runSpecificTest(testIndex);
}

int	TestManager::validateTestSelection(std::string input){
	int	nbrTests = UnitTest::getTotalTest() -1, testInputChosen = 0;
	std::stringstream(input) >> testInputChosen;

	if (input.empty())
		return 1;
	for (int x = 0; x < static_cast<int>(input.length()); x++)
		if (!std::isdigit(input.c_str()[x]))
			return 1;
	if (testInputChosen < 0 || testInputChosen > nbrTests)
		return 1;
	return 0;
}