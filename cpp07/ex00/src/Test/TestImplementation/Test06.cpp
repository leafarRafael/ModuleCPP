/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test06.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 13:34:41 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "whatever.hpp"
#include <iostream>

int	test06(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                            max int:\n");
	Debug::stop = 0;

	Debug::msg(1, GREEN ITALI BOLD "int a = 42, b = 1, _returned;\n");
	int a = 42, b = 1, _returned;

	Debug::msg(1, GREEN ITALI BOLD "_returned = max(a, b);\n");
	_returned = max(a, b);

	std::cout << GREEN ITALI BOLD "Value a: " RESET << a << '\n';
	std::cout << GREEN ITALI BOLD "Value b: " RESET << b << "\n";
	std::cout << GREEN ITALI BOLD "Value _returned: " RESET << _returned << "\n\n\n";
	if (_returned == a)
		return 0;		
	Debug::stop = 1;
	return (1);
}
