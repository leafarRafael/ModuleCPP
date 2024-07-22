/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:11:11 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/22 09:03:32 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include <cstdlib>

int main()
{
	PhoneBook	_phoneBook;
	std::string input;
	int			index, ctrl, nbr_contact;

	index = 0;
	nbr_contact = 0;
	ctrl = 0;
	while (1)
	{
		std::cout << "Option: ADD, SEARCH and EXIT.\n"
			<< "Make your choice: ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			_phoneBook.exitProgram();
		else if (input == "ADD")
		{
			if (!_phoneBook.addContact(index) && !ctrl)
				nbr_contact++;
		}
		else if (input == "SEARCH")
			_phoneBook.searchContact(nbr_contact);
		else
			std::cout << "Option not found.\n\n";
		if (index == 8)
		{
			index = 0;
			ctrl++;
		}
	}
	return (1);
}