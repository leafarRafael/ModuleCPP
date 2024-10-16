/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 15:46:45 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "iter.hpp"
#include <iostream>
#include <cctype>

void	func(char &c);
int		func1(char &c);
char	func2(char &c);
long	func3(char &c);
double	func4(char &c);
float	func5(char &c);


int	test00(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                            swap int:\n");
	Debug::stop = 0;

	char array[] = {'a', 'b', 'c', 'd' };
	//int int_array[] = {'a', 'b', 'c', 'd' };
	
	::iter(array, sizeof(array), func);
	::iter(array, sizeof(array), func1);
	::iter(array, sizeof(array), func2);
	::iter(array, sizeof(array), func3);
	::iter(array, sizeof(array), func4);
	::iter(array, sizeof(array), func5);

	Debug::stop = 1;
	return (1);
}

void	func(char &c){
	c += 1;
	std::cout << c << '\n';
}

int		func1(char &c){
	c += 1;
	std::cout << c << '\n';
	return c;
}

char	func2(char &c){
	c += 4;
	std::cout << c << '\n';
	return c;
}

long	func3(char &c){
	c += 4;
	std::cout << c << '\n';
	return c;
}

double	func4(char &c){
	c += 4;
	std::cout << c << '\n';
	return c;
}

float	func5(char &c){
	c += 4;
	std::cout << c << '\n';
	return c;
}