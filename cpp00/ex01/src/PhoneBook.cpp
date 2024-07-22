/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:47:17 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/22 09:11:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

static std::string addAtt(std::string option);
static std::string formater(std::string input);

int	PhoneBook::addContact(int & index)
{
	std::string input[5];

	input[0] = addAtt("First Name: ");
	input[1] = addAtt("Last Name: ");
	input[2] = addAtt("Nick Name: ");
	input[3] = addAtt("Phone Number: ");
	input[4] = addAtt("Darkest Secret: ");
	if (input[0].empty() ||  input[1].empty() || input[2].empty() 
		|| input[3].empty() || input[4].empty())
		return (1);
	Contact contact(input[0], input[1], input[2], input[3],input[4]);
	_contact[index] = contact;
	index++;
	return (0);

}

void PhoneBook::exitProgram()
{
	std::cout << "\n\nBye bye!\n\n";
	exit(0);
}

void PhoneBook::searchContact(int index)
{
	std::string	search;
	int			inputNbr;

	putContact(index);;
	std::cout << "enter the contact index: ";
	std::getline(std::cin, search);
	if (search.length() > 1 || !isdigit(search[0]))
	{
		std::cout << "\"" << search << "\"" 
		<< " I expect values between 0 and 7\n";
		return ;
	}
	std::istringstream(search) >> inputNbr;
	if (inputNbr < index)
		fullContact(inputNbr);
	else
		std::cout << "Range Wrong\n";
}

void PhoneBook::putContact(int index)
{
	std::ostringstream indexString;

	indexString << index;
	std::cout << " -------------------------------------------\n";
	std::cout << "|  Index   |Firt Name |Last Name |Nick Name |\n";
	std::cout << " -------------------------------------------\n";
	for (int i = 0; i < index; i++)
		allContact(i);
	std::cout << " -------------------------------------------\n";
}

void PhoneBook::allContact(int index)
{
	std::ostringstream indexString;

	indexString << index;
	std::cout << "|" << formater(indexString.str())  << "|"
		<< formater(_contact[index].getFirstName()) << "|"
		<< formater(_contact[index].getLastName()) << "|"
		<< formater(_contact[index].getNickName()) << "|\n";
}

static std::string formater(std::string input)
{
	std::string formatted;

	if (input.length() > 10)
		formatted = input.substr(0, 9) + "." ;
	else if (input.length() < 10)
		formatted = std::string(10 - input.length(), ' ') + input;
	else
		formatted = input;
	return (formatted);
}

static std::string addAtt(std::string option)
{
	std::string input;

	std::cout << option;
	std::getline(std::cin, input);
	return (input);
}

void PhoneBook::fullContact(int index)
{
	std::cout << "First name: " << _contact[index].getFirstName() << std::endl
		<< "Last name: " << _contact[index].getLastName() << std::endl
		<< "Nick name: " << _contact[index].getNickName() << std::endl
		<< "Phone Number: " << _contact[index].getPhoneNumber() << std::endl
		<< "Darkest Secret: " << _contact[index].getDarkestSecret() << std::endl;
}