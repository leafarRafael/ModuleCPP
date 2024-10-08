/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/06 13:11:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include "Collor.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

static void format_msg(const char *msg1, const char *msg2);
static void turn_msg(const std::string name);
static void defineTurnAction(ClapTrap & active, ClapTrap & passive);
int test();
static void msgTest(std::string msg);
int (*select_test(int i))();
int	nbr_teste = 2;

int main()
{
	test();
	return 0;
}

int test() {
	int 		value_status;
	std::string	msg_status;

	for(int i = 0; i < nbr_teste; i++)
	{
		value_status = 0;
		msg_status = OK;
		value_status = (*select_test(i))();
		if (value_status)
			msg_status = FAILED;
		std::cout << STATUS << msg_status;
	}
	std::cout << std::endl;
	return 0;
}

int test00(){
	msgTest(" Testes mothods orthodox ");

	std::cout << GREEN "\n ** Object initialization methods **\n" RESET;
	ClapTrap b;
	format_msg(NULL, "ClapTrap b;");
	ClapTrap a("Kimberly");
	format_msg(NULL, "ClapTrap a(\"Kimberly\");");
	ClapTrap c(a);
	format_msg(NULL, "ClapTrap c(a);");
	b = a;
	format_msg(NULL, "b = a;");

	std::cout << GREEN "\n ** Methods seters **\n" RESET;
	format_msg("setName:\n", "a.setName(\"Richard\");");
	a.setName("Richard");
	format_msg("setHitPoints:\n", "a.setHitPoints(150);");
	a.setHitPoints(150);
	format_msg("setAttackDamage:\n", "a.setAttackDamage(40);");
	a.setAttackDamage(40);
	format_msg("setEnergyPoints:\n", "a.setEnergyPoints(100);");
	a.setEnergyPoints(100);

	std::cout << GREEN "\n ** Methods geters **\n" RESET;
	std::cout 
		<< BLUE << "getName: \n" << RESET
			<< "a.getName(); = " << a.getName() << '\n'
		<< BLUE << "getHitPoints: \n" << RESET
			<< "a.getHitPoints(); = " << a.getHitPoints() << '\n'
		<< BLUE << "getAttackDamage: \n" << RESET
			<< "a.getAttackDamage();  = " << a.getAttackDamage() << '\n'
		<< BLUE << "getEnergyPoints: \n" << RESET
			<< "a.getEnergyPoints(); = " << a.getEnergyPoints() << '\n';

	std::cout << GREEN "\n ** Destuctor default **\n" RESET;
	return (0);
}

int test01(){
	msgTest(" Testes member functions ");

	ClapTrap tory("Tory");
	format_msg(NULL, "ClapTrap tory(\"Tory\");");
	ClapTrap kimberly("Kimberly");
	format_msg(NULL, "ClapTrap kimberly(\"Kimberly\");");

	tory.setAttackDamage(20);
	tory.setEnergyPoints(100);
	tory.setHitPoints(100);
	kimberly.setAttackDamage(20);
	kimberly.setEnergyPoints(100);
	kimberly.setHitPoints(100);
	std::srand(std::time(0));
	int	i = 1;
	while (true)
	{
		usleep(700000);
		if (!kimberly.getHitPoints() || !tory.getHitPoints())
			return (0);
		int	turn = std::rand() % 100;
		if (turn % i != 0)
			defineTurnAction(tory, kimberly);
		else
			defineTurnAction(kimberly, tory);
		i++;
	}
	return (0);
}

int (*select_test(int i))(){
	int	(*function[4])() = {
		test00,
		test01,
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

static void format_msg(const char *msg1, const char *msg2)
{
	if (msg1)
		std::cout << BLUE << std::string(msg1) << RESET;
	if (msg2)
		std::cout << std::string(msg2) << std::endl;
	else
		std::cout << std::endl;
}

static void turn_msg(const std::string name)
{
	std::cout << YELLOW
		<< "\n              **** "<< "  Turn  " << name << "     ***\n"
		<< RESET;
}

static void defineTurnAction(ClapTrap & active, ClapTrap & passive)
{
	turn_msg(active.getName());
	if (active.getHitPoints() < 50 && passive.getHitPoints() > 50)
		active.beRepaired(10);
	else
	{
		active.attack(passive.getName());
		passive.takeDamage(active.getAttackDamage());
	}
}