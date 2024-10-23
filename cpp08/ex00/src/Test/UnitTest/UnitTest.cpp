/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnitTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:52:49 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/17 11:30:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UnitTest.hpp"
#include <iostream>
#include "Color.hpp"
#include "Debug.hpp"

int UnitTest::totalTest = 2;

int	(*UnitTest::select_test(int i))(){
	int	(*function[10])() = {
		test00,
		test01,
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