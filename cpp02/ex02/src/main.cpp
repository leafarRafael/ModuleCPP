/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/24 10:32:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int test00();
int test02();
int test01();
int test();
int (*select_test(int i))();

int main()
{
	test();
	return 0;
}

int test()
{
	int 		value_status;
	std::string	msg_status;

	for(int i = 0; i < 3; i++)
	{
		value_status = 0;
		msg_status = " [OK] ";
		std::cout << "Iniciando Teste: [" << i << "]\n";
		value_status = (*select_test(i))();
		if (value_status)
			msg_status = " [Failed] ";
		std::cout << "Teste ["<< i << "] finalizado, status:" << msg_status << "\n\n";
	}
	return 0;
}

int (*select_test(int i))()
{
	int	(*function[3])() = {test00, test01, test02};

	return (function[i]);
}

int test00()
{
	std::srand(std::time(NULL));
	int		i = std::rand() % 10;
	Fixed	a(i);
	Fixed	b(i);

	std::cout << "Overload incremente pos:\n";
	std::cout << "Valor inicial randomico: " << b++ << std::endl;
	std::cout << "valor inicial: " << b << std::endl;
	return (0);
}

int test01()
{
	return (0);
}

int test02()
{
	return (1);
}
