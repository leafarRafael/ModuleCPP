/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnitTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:52:49 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 13:28:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UnitTest.hpp"
#include <iostream>
#include "Color.hpp"
#include "Debug.hpp"

int UnitTest::totalTest = 9;

int	(*UnitTest::select_test(int i))(){
	int	(*function[10])() = {
		test00,
		test01,
		test02,
		test03,
		test04,
		test05,
		test06,
		test07,
		test08,
		};
	return (function[i]);
}

int	UnitTest::getTotalTest(){
	return totalTest;
}

std::string	getInputTest(){
	std::string		input;
	std::getline(std::cin, input);
	return input;
}