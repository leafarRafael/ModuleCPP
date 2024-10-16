/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test05.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 13:34:33 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "whatever.hpp"
#include <iostream>

int	test05(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                            min char:\n");
	Debug::stop = 0;

	Debug::msg(1, GREEN ITALI BOLD "char a = 'Z', b = 'A', _returned;\n");
	char a = 'Z', b = 'A', _returned;

	Debug::msg(1, GREEN ITALI BOLD "_returned = min(a, b);\n");
	_returned = min(a, b);

	std::cout << GREEN ITALI BOLD "Value a: " RESET << a << '\n';
	std::cout << GREEN ITALI BOLD "Value b: " RESET << b << "\n";
	std::cout << GREEN ITALI BOLD "Value _returned: " RESET << _returned << "\n\n\n";
	if (_returned == b)
		return 0;		
	Debug::stop = 1;
	return (1);
}
