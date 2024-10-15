/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 08:27:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include <iostream>
#include "UnitTest.hpp"
#include "Data.hpp"
#include "Serialization.hpp"

int	test00(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                            Serialization:\n");
	Debug::stop = 0;
	Debug::msg(1, GREEN ITALI SUBLI BOLD "\n      Serialize and Deserialize:\n");

	Debug::msg(1, GREEN ITALI SUBLI BOLD "\nData data(\"Instanci of Data\", 42, \"Erpmes\");\n");
	Data data("Instanci of Data", 42, "Erpmes");
	std::cout << "Addr data: " << &data << "\n\n";

	Debug::msg(1, GREEN ITALI SUBLI BOLD "uintptr_t rawBits = Serialization::serialize(&data);\n");
	uintptr_t rawBits = Serialization::serialize(&data);
	std::cout << "RawBits: " << rawBits << "\n\n";

	Debug::msg(1, GREEN ITALI SUBLI BOLD "Data *ptrData = Serialization::deserialize(rawBits);\n");
	Data *ptrData = Serialization::deserialize(rawBits);
	std::cout << "Addr ptrData: " << ptrData << "\n";

	Debug::stop = 1;
	return (0);
}
