/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/13 10:59:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include <iostream>
#include <cctype>
#include "easyfind.hpp"
#include <vector>

int	test01(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                         iter ptr Function tolower:\n");
	Debug::msg(1, GREEN ITALI SUBLI BOLD "   Expectation to find the element.\n");

	std::vector<int > vec;

	for (int i = 0; i < 20; i++){
		vec.push_back(i);
	}
	try{
		std::cout << *easyfind(vec, 2) << "\n\n\n";
	} catch(std::exception &e){
		std::cerr << e.what() << "\n";
		return 1;
	}
	return 0;
}
