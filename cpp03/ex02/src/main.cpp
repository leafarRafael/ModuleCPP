/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/06 18:44:07 by rbutzke          ###   ########.fr       */
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
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void format_msg(const char *msg1, const char *msg2);
static void turn_msg(const std::string name);
static void clapTurnAction(ClapTrap & active, ClapTrap & passive);
static void childrenTurnAction(ClapTrap & scav, ClapTrap & passive1, ClapTrap & passive2);
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
	msgTest(" Testes mothods orthodox ScavTrap");

	std::cout << GREEN "\n ** Object initialization methods ** \n" RESET;
	format_msg("\n", "ScavTrap orvil;");
	ScavTrap orvil;
	format_msg("\n", "ScavTrap a(\"Loren\");");
	ScavTrap loren("Loren");
	format_msg("\n", "ScavTrap c(a);");
	ScavTrap bob(loren);
	format_msg("\n", "orvil = loren;");
	orvil = bob;

	bob.setName("Bob");
	std::cout << GREEN "\n ** Methods seters **\n" RESET;
	format_msg("setName:\n", "orvil.setName(\"orvil\");");
	orvil.setName("orvil");
	format_msg("setHitPoints:\n", "orvil.setHitPoints(150);");
	orvil.setHitPoints(150);
	format_msg("setAttackDamage:\n", "orvil.setAttackDamage(40);");
	orvil.setAttackDamage(40);
	format_msg("setEnergyPoints:\n", "orvil.setEnergyPoints(100);");
	orvil.setEnergyPoints(100);

	std::cout << GREEN "\n ** Methods geters **\n" RESET;
	std::cout 
		<< BLUE << "getName: \n" << RESET
			<< "loren.getName(); = " << loren.getName() << "\n\n"
		<< BLUE << "getHitPoints: \n" << RESET
			<< "loren.getHitPoints(); = " << loren.getHitPoints() << "\n\n"
		<< BLUE << "getAttackDamage: \n" << RESET
			<< "loren.getAttackDamage();  = " << loren.getAttackDamage() << "\n\n"
		<< BLUE << "getEnergyPoints: \n" << RESET
			<< "loren.getEnergyPoints(); = " << loren.getEnergyPoints() << "\n\n";

	std::cout << GREEN "\n ** Destuctor default **\n" RESET;
	return (0);
}

int test02(){
	msgTest(" Testes mothods orthodox FragTrap ");

	std::cout << GREEN "\n ** Object initialization methods ** \n" RESET;
	format_msg("\n", "FragTrap onisne;");
	FragTrap onisne;
	
	format_msg("\n", "FragTrap emulov(\"emulov\");");
	FragTrap emulov("Emulov");
	
	format_msg("\n", "FragTrap osson(emulov);");
	FragTrap osson(emulov);
	
	format_msg("\n", "onisne = emulov;");
	onisne = osson;

	osson.setName("Osson");
	std::cout << GREEN "\n ** Methods seters **\n" RESET;
	format_msg("setName:\n", "osson.setName(\"osson\");");
	osson.setName("osson");
	format_msg("setHitPoints:\n", "osson.setHitPoints(150);");
	osson.setHitPoints(150);
	format_msg("setAttackDamage:\n", "osson.setAttackDamage(40);");
	osson.setAttackDamage(40);
	format_msg("setEnergyPoints:\n", "osson.setEnergyPoints(100);");
	osson.setEnergyPoints(100);

	std::cout << GREEN "\n ** Methods geters **\n" RESET;
	std::cout 
		<< BLUE << "getName: \n" << RESET
			<< "osson.getName(); = " << osson.getName() << "\n\n"
		<< BLUE << "getHitPoints: \n" << RESET
			<< "osson.getHitPoints(); = " << osson.getHitPoints() << "\n\n"
		<< BLUE << "getAttackDamage: \n" << RESET
			<< "osson.getAttackDamage();  = " << osson.getAttackDamage() << "\n\n"
		<< BLUE << "getEnergyPoints: \n" << RESET
			<< "osson.getEnergyPoints(); = " << osson.getEnergyPoints() << "\n\n";
	emulov.highFivesGuys();
	std::cout << GREEN "\n ** Destuctor default **\n" RESET;
	return (0);
}

int test03(){
	msgTest(" Testes member functions ");

	ClapTrap tory("Tory");
	format_msg(NULL, "ClapTrap tory(\"Tory\");");
	ClapTrap kimberly("Kimberly");
	format_msg(NULL, "ClapTrap kimberly(\"Kimberly\");");
	ScavTrap bob("Bob");
	format_msg(NULL, "ScavTrap bob(\"Bob\");");
	FragTrap emulov("Emulov");
	format_msg(NULL, "FragTrap emulov(\"Emulov\");");

	tory.setAttackDamage(10);
	tory.setEnergyPoints(20);
	tory.setHitPoints(60);
	kimberly.setAttackDamage(10);
	kimberly.setEnergyPoints(20);
	kimberly.setHitPoints(60);

	std::srand(std::time(0));
	bob.guardGate();
	while (true)
	{
		usleep(750000);
		if ((!kimberly.getHitPoints() && !tory.getHitPoints()) || !bob.getHitPoints())
			break ;
		int	turn = std::rand() % 10 ;
		if ((turn >= 1 && turn <= 3) || (turn >= 6 && turn <= 8))
		{
			if (tory.getEnergyPoints() && tory.getHitPoints())
				clapTurnAction(tory, bob);
			if (kimberly.getEnergyPoints() && kimberly.getHitPoints())
				clapTurnAction(kimberly, bob);
		}
		else
			childrenTurnAction(bob, kimberly, tory);
	}
	while (true)
	{
		usleep(750000);
		if ((!kimberly.getHitPoints() && !tory.getHitPoints()) || !emulov.getHitPoints())
			break ;
		int	turn = std::rand() % 10 ;
		if ((turn >= 1 && turn <= 3) || (turn >= 6 && turn <= 8))
		{
			if (tory.getEnergyPoints() && tory.getHitPoints())
				clapTurnAction(tory, emulov);
			if (kimberly.getEnergyPoints() && kimberly.getHitPoints())
				clapTurnAction(kimberly, emulov);
		}
		else
			childrenTurnAction(emulov, kimberly, tory);
	}
	if (!kimberly.getHitPoints() && tory.getHitPoints())
		emulov.highFivesGuys();
	emulov.highFivesGuys();
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

static void clapTurnAction(ClapTrap & active, ClapTrap & passive)
{
	if (!passive.getHitPoints() || !active.getHitPoints())
		return ;
	turn_msg(active.getName());
	if (active.getHitPoints() < 30 )
		active.beRepaired(30);
	else
	{
		active.attack(passive.getName());
		passive.takeDamage(active.getAttackDamage());
	}
}

static void childrenTurnAction(ClapTrap & scav, ClapTrap & passive1, ClapTrap & passive2)
{
	std::srand(std::time(0));
	int	turn = std::rand() % 10;

	if (scav.getHitPoints() <= 20)
		scav.beRepaired(10);
	if (turn % 2 == 0)
	{
		if (passive1.getHitPoints())
		{
			turn_msg(scav.getName());
			scav.attack(passive1.getName());
			passive1.takeDamage(scav.getAttackDamage());
		}
	}
	else
	{
		if (passive2.getHitPoints())
		{
			turn_msg(scav.getName());
			scav.attack(passive2.getName());
			passive2.takeDamage(scav.getAttackDamage());
		}
	}
}