/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/05 13:16:27 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define OK		" [\033[32mOK\033[0m] "
#define FAILED	" [\033[31mFailed\033[0m] ";
#define STATUS	"\033[34mStatus:\033[0m"

static void type(std::string msg);
static void result(Fixed expected, Fixed result);
static void putObject(Fixed object);
int test();
int (*select_test(int i))();
int	nbr_teste = 17;

int main()
{
	test();
	return 0;
}

int test() {
	int 		value_status;
	std::string	msg_status;

	std::cout << YELLOW  << "\n=================================================\n" << RESET;
	for(int i = 0; i < nbr_teste; i++)
	{
		value_status = 0;
		msg_status = OK;
		std::cout << "Test: [" << (i) << "]" ;
		value_status = (*select_test(i))();
		if (value_status)
			msg_status = FAILED;
		std::cout << STATUS << msg_status;
		std::cout << YELLOW << "\n=================================================\n" << RESET;
	}
	std::cout << std::endl;
	return 0;
}

int test00(){
	Fixed object(42.42f);

	type("** Post increment [object++] **");
	putObject(object);
	for(int i = 0; i < 42;i++)
		object++;
	std::cout << MAGENTA << "Value after operation 42 times = [" << BLUE << object << MAGENTA << ']' << RESET << '\n';
	if (object.toFloat() != 42.42f)
		return (0);
	return (1);
}

int test01(){
	Fixed object(42.42f);

	type("** Post decrement [object--] **");
	putObject(object);
	for(int i = 0; i < 42;i++)
		object--;
	std::cout << MAGENTA << "Value after operation 42 times = [" << BLUE << object << MAGENTA << ']' << RESET << '\n';
	if (object.toFloat() != 42.42f)
		return (0);
	return (1);
}

int test02(){
	Fixed object(42.42f);

	type("** Pre decrement [--object] **");
	putObject(object);
	for(int i = 0; i < 42;i++)
		--object;
	std::cout << MAGENTA << "Value after operation 42 times = [" << BLUE << object << MAGENTA << ']' << RESET << '\n';
	if (object.toFloat() != 42.42f)
		return (0);
	return (1);
}

int test03(){
	Fixed object(42.42f);

	type("** Pre increment [++object] **");
	putObject(object);
	for(int i = 0; i < 42;i++)
		++object;
	std::cout << MAGENTA << "Value after operation 42 times = [" << BLUE << object << MAGENTA << ']' << RESET << '\n';
	if (object.toFloat() != 42.42f)
		return (0);
	return (1);
}

int test04(){
	Fixed objectA(42.24f);
	Fixed objectB(42.42f);

	type("** comparison operators [objectA < objectB] **");
	putObject(objectA);
	putObject(objectB);
	if (objectA < objectB)
		return (0);
	return (1);
}

int test05(){
	Fixed objectA(24.24f);
	Fixed objectB(42.42f);

	type("** comparison operators [objectA <= objectB] **");
	putObject(objectA);
	putObject(objectB);
	if (objectA <= objectB)
		return (0);
	return (1);
}

int test06(){
	Fixed objectA(84.24f);
	Fixed objectB(42.42f);

	type("** comparison operators [objectA > objectB] **");
	putObject(objectA);
	putObject(objectB);
	if (objectA > objectB)
		return (0);
	return (1);
}

int test07(){
	Fixed objectA(84.24f);
	Fixed objectB(84.24f);

	type("** comparison operators [objectA >= objectB] **");
	putObject(objectA);
	putObject(objectB);
	if (objectA >= objectB)
		return (0);
	return (1);
}

int test08(){
	Fixed objectA(84.24f);
	Fixed objectB(84.24f);

	type("** comparison operators [objectA == objectB] **");
	putObject(objectA);
	putObject(objectB);
	if (objectA == objectB)
		return (0);
	return (1);
}

int test09(){
	Fixed objectA(42.1f);
	Fixed objectB(42.1f);
	Fixed objectR(objectA + objectB);
	Fixed objectResult(84.2031f);

	type("** arithmetic operators [objectA + objectB] **");
	putObject(objectA);
	putObject(objectB);
	result(objectResult, objectR);
	if (objectR == objectResult)
		return (0);
	return (1);
}

int test10(){
	Fixed objectA(84.2032f);
	Fixed objectB(42.1016f);
	Fixed objectR(objectA - objectB);
	Fixed objectResult(42.1016f);

	type("** arithmetic operators [objectA - objectB] **");
	putObject(objectA);
	putObject(objectB);
	result(objectResult, objectR);
	if (objectR == objectResult)
		return (0);
	return (1);
}

int test11(){
	Fixed objectA(42.1016f);
	Fixed objectB(2);
	Fixed objectR(objectA * objectB);
	Fixed objectResult(84.2032f);

	type("** arithmetic operators [objectA * objectB] **");
	putObject(objectA);
	putObject(objectB);
	result(objectResult, objectR);
	if (objectR == objectResult)
		return (0);
	return (1);
}

int test12(){
	Fixed objectA(84.2032f);
	Fixed objectB(2);
	Fixed objectR(objectA / objectB);
	Fixed objectResult(42.1016f);

	type("** arithmetic operators [objectA / objectB] **");
	putObject(objectA);
	putObject(objectB);
	result(objectResult, objectR);
	if (objectR == objectResult)
		return (0);
	return (1);
}

int test13(){
	Fixed objectA(42.42f);
	Fixed objectB(1.1f);
	Fixed objectR = Fixed::max(objectA, objectB);
	Fixed &objectResult = objectA;

	type("** max return ref [objectA > objectB] **");
	putObject(objectA);
	putObject(objectB);
	result(objectResult, objectR);
	if (objectR == objectResult)
		return (0);
	return (1);
}

int test14(){
	Fixed objectA(42.42f);
	Fixed objectB(1.1f);
	Fixed objectR = Fixed::min(objectA, objectB);
	Fixed &objectResult = objectB;

	type("** min return ref [objectA < objectB] **");
	putObject(objectA);
	putObject(objectB);
	result(objectResult, objectR);
	if (objectR == objectResult)
		return (0);
	return (1);
}

int test15(){
	Fixed const objectA(42.42f);
	Fixed const objectB(1.1f);
	Fixed const objectR = Fixed::max(objectA, objectB);
	Fixed const &objectResult = objectA;

	type("** max return const ref [objectA > objectB] **");
	putObject(objectA);
	putObject(objectB);
	result(objectResult, objectR);
	if (objectR.toFloat() == objectResult.toFloat())
		return (0);
	return (1);
}

int test16(){
	Fixed const objectA(42.42f);
	Fixed const objectB(1.1f);
	Fixed const objectR = Fixed::min(objectA, objectB);
	Fixed const &objectResult = objectB;

	type("** min return const ref [objectA < objectB] **");
	putObject(objectA);
	putObject(objectB);
	result(objectResult, objectR);
	if (objectR.toFloat() == objectResult.toFloat())
		return (0);
	return (1);
}

int (*select_test(int i))(){
	int	(*function[17])() = {
		test00,
		test01,
		test02,
		test03,
		test04,
		test05,
		test06,
		test07,
		test08,
		test09,
		test10,
		test11,
		test12,
		test13,
		test14,
		test15,
		test16};

	return (function[i]);
}

static void type(std::string msg){
	std::cout << CYAN << "\n" << msg << "\n\n" << RESET;
}

static void putObject(Fixed object)
{
	std::cout << MAGENTA << "Object instantiated with value = [" << RESET;
	std::cout << GREEN << object << MAGENTA << ']' << RESET << '\n';
}

static void result(Fixed expected, Fixed result)
{

	std::cout << MAGENTA "Expected = " GREEN << expected << RESET << std::endl;
	std::cout << MAGENTA << "Result = " << GREEN << result << RESET << std::endl;
}