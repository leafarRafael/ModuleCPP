/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test02.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 13:34:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "whatever.hpp"
#include <iostream>

int	test02(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                            swap char:\n");
	Debug::stop = 0;
	Debug::msg(1, GREEN ITALI BOLD "char a = 'A', b = 'B';\n");
	char a = 'A', b = 'B';
	Debug::msg(1, GREEN ITALI BOLD "swap(&a, &b);\n");
	swap(&a, &b);
	std::cout << GREEN ITALI BOLD "Value a: " RESET << a << '\n';
	std::cout << GREEN ITALI BOLD "Value b: " RESET << b << "\n\n\n";
	if (a == 'B' || b == 'A')
		return 0;		
	Debug::stop = 1;
	return (1);
}
