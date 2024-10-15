/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test02.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 08:55:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include <iostream>
#include "UnitTest.hpp"
#include "Data.hpp"
#include "OtherData.hpp"
#include "Serialization.hpp"
#include <cstring>


int	test02(){ 
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                                reinterpret_cast :\n");
	Debug::stop = 0;
	Debug::msg(1, GREEN ITALI SUBLI BOLD "\n        Converting objects of different classes:\n");
	Debug::msg(1, GREEN ITALI SUBLI BOLD "   Attributes lastName with different types:\n");

	Debug::msg(1, BLUE ITALI BOLD "\nOtherData objectOtherData;\n");
	OtherData	objectOtherData;
	Debug::msg(1, BLUE ITALI BOLD "\nchar *array = new char[30];\n");
	char *array = new char[30];
	Debug::msg(1, BLUE ITALI BOLD "\nstd::strcpy(array, \"Is char* poiter\");\n");
	std::strcpy(array, "Is char* poiter");
	Debug::msg(1, BLUE ITALI BOLD "\nobjectOtherData.setName(\"OtherData\");\n");
	objectOtherData.setName("OtherData");
	Debug::msg(1, BLUE ITALI BOLD "\nobjectOtherData.setValue(42);\n");
	objectOtherData.setValue(42);
	Debug::msg(1, BLUE ITALI BOLD "\nobjectOtherData.setLastName(array);\n");
	objectOtherData.setLastName(array);
	Debug::msg(1, BLUE ITALI BOLD "\nLastName in OtherData is a char *ptr.\n");
	Debug::msg(1, BLUE ITALI BOLD "\nLastName in Data is a std::string.\n");

	Debug::msg(1, BLUE ITALI BOLD "\nData *dataObject = reinterpret_cast<Data*>(&objectOtherData); \n");
	Data *dataObject = reinterpret_cast<Data*>(&objectOtherData); 
	Debug::msg(1, BLUE ITALI BOLD "\ndataObject->getName(); \n");
	std::cout << "Name: "<< dataObject->getName() << '\n';
	Debug::msg(1, BLUE ITALI BOLD "\ndataObject->getValue(); \n");
	std::cout << "Value: " << dataObject->getValue() << "\n";
	Debug::msg(1, BLUE ITALI BOLD "\ndataObject.getLastName()\n");
	std::cout << "LastName: " << dataObject->getLastName() << '\n';
	Debug::msg(1, BLUE ITALI BOLD "\nobjectOtherData.getLastName()\n");
	std::cout << "LastName: " << objectOtherData.getLastName() << '\n';
	delete [] array;

	Debug::stop = 1;
	return (0);
}

