/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:59:58 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 11:09:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void){
	int	randomNum;

	srand(time(0));
	randomNum = rand() % 3;
	switch(randomNum){
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break ;
		case 2:
			return new C();
			break; 
		default:
			break ;
	}
	return 0;
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "It's a class A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "It's a class B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "It's a class C\n";
	else
		std::cout << "Unknown a poiter.\n";
		
}

void	identify(Base& p){
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "It's a class A\n";
		(void)&a;
	}catch(std::exception &e){}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "It's a class B\n";
		(void)&b;
	}catch(std::exception &e){}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "It's a class C\n";
		(void)&c;
	}catch(std::exception &e){}
}

