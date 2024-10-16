/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 13:34:01 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "whatever.hpp"
#include <iostream>

int	test01(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                            swap double:\n");
	Debug::stop = 0;
	Debug::msg(1, GREEN ITALI BOLD "double a = 42.2, b = 1.1;\n");
	double a = 42.2, b = 1.1;
	Debug::msg(1, GREEN ITALI BOLD "swap(&a, &b);\n");
	swap(&a, &b);
	std::cout << GREEN ITALI BOLD "Value a: " RESET << a << '\n';
	std::cout << GREEN ITALI BOLD "Value b: " RESET << b << "\n\n\n";
	if (a == 1.1 || b == 42.2)
		return 0;		
	Debug::stop = 1;
	return (1);
}
