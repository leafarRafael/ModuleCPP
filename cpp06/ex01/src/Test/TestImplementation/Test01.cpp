/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 08:40:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include <iostream>
#include "UnitTest.hpp"
#include "Data.hpp"
#include "OtherData.hpp"
#include "Serialization.hpp"
#include <cstring>


int	test01(){ 
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                                reinterpret_cast :\n");
	Debug::stop = 0;
	Debug::msg(1, GREEN ITALI SUBLI BOLD "\n        Converting objects of different classes:\n");

	Debug::msg(1, BLUE ITALI BOLD "\nOtherData objectOtherData;\n");
	OtherData	objectOtherData;
	Debug::msg(1, BLUE ITALI BOLD "\nobjectOtherData.setName(\"OtherData\");\n");
	objectOtherData.setName("OtherData");
	Debug::msg(1, BLUE ITALI BOLD "\nobjectOtherData.setValue(42);\n");
	objectOtherData.setValue(42);
	Debug::msg(1, BLUE ITALI BOLD "\nData *dataObject = reinterpret_cast<Data*>(&objectOtherData); \n");
	Data *dataObject = reinterpret_cast<Data*>(&objectOtherData); 
	Debug::msg(1, BLUE ITALI BOLD "\ndataObject->getName(); \n");
	std::cout << "Name: "<< dataObject->getName() << '\n';
	Debug::msg(1, BLUE ITALI BOLD "\ndataObject->getValue(); \n");
	std::cout << "Value: " << dataObject->getValue() << "\n\n";

	Debug::stop = 1;
	return (0);
}
