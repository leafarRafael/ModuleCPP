/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/05 17:19:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include "Collor.hpp"

int test();
static void msgTest(std::string msg);
int (*select_test(int i))();
int	nbr_teste = 4;

int main()
{
	test();
	return 0;
}

int test() {
	int 		value_status;
	std::string	msg_status;

	std::cout << YELLOW  << "\n==========================================================================================\n" << RESET;
	for(int i = 0; i < nbr_teste; i++)
	{
		value_status = 0;
		msg_status = OK;
		std::cout << "Test: [" << (i) << "]" ;
		value_status = (*select_test(i))();
		if (value_status)
			msg_status = FAILED;
		std::cout << STATUS << msg_status;
		std::cout << YELLOW  << "\n==========================================================================================\n" << RESET;
	}
	std::cout << std::endl;
	return 0;
}

int test00(){
	msgTest(" Testes mothods orthodox canonical form, geters and seters");

	std::cout << "________________________________________________________________\n";
	std::cout << "\n                  Instantiating objects\n";
	std::cout << "________________________________________________________________\n\n";
	ClapTrap b;
	ClapTrap a("Kimberly");
	ClapTrap c(a);
	b = a;

	a.setName("Richard");
	a.setHitPoints(150);
	a.setAttackDamage(40);
	a.setEnergyPoints(100);
	b.setName("Richard");
	std::cout << "getName: " << b.getName() << std::endl
		<< "________________________________________________________________\n\n"
			<< "getHitPoints: " << b.getHitPoints() << std::endl
		<< "________________________________________________________________\n\n"
			<< "getAttackDamage: " << b.getAttackDamage() << std::endl
		<< "________________________________________________________________\n\n"
			<< "getEnergyPoints: " << b.getEnergyPoints() << std::endl;
	std::cout << "________________________________________________________________\n\n";
	return (0);
}

int test01(){
	msgTest(" Testes member functions ");

	ClapTrap b("Tory");
	ClapTrap a("Kimberly");
	b.setAttackDamage(20);
	b.setEnergyPoints(100);
	b.setHitPoints(100);
	a.setAttackDamage(20);
	a.setEnergyPoints(100);
	a.setHitPoints(100);
	return (0);
}

int test02(){

	return (0);
}

int test03(){

	return (0);
}

int (*select_test(int i))(){
	int	(*function[4])() = {
		test00,
		test01,
		test02,
		test03,
		};
	return (function[i]);
}

static void msgTest(std::string msg)
{
	std::string lineup(msg.length() + (std::string(FORM).length() * 2), '=');
	std::string linedown(msg.length() + (std::string(FORM).length() * 2), '=');

	std::cout << '\n' << MAGENTA << lineup << RESET << '\n';
	std::cout << '\n' << MAGENTA FORM << msg << FORM RESET << std::endl;
	std::cout << '\n' << MAGENTA << linedown << RESET << '\n';
}