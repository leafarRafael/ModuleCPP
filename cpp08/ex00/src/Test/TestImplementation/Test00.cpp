/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/17 11:36:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "iter.hpp"
#include <iostream>
#include <cctype>

static void	put(char const c);

int	test00(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                         iter ptr Function toupper:\n");
	Debug::msg(1, GREEN ITALI SUBLI BOLD "   expectation that changes the statement.\n");

	Debug::msg(1, DECLFORMAT "\n   char array[] = {'a', 'b', 'c', 'd' };\n");
	char array[] = {'a', 'b', 'c', 'd' };
	Debug::msg(1, DECLFORMAT "::iter(array, sizeof(array), static_cast<int(*)(int)>(std::toupper));\n");
	::iter(array, sizeof(array), static_cast<int(*)(int)>(std::toupper));
	::iter(static_cast<const char *>(array), sizeof(array), put);
	std::cout << std::endl;
	int status = 0;
	for (int i = 0; i < 4; i++){
		if (std::islower(array[i]))
			status++;
	}
	if (status)
		return 1;
	return 0;
}

static void	put(char const c){
	std::cout << c;
}