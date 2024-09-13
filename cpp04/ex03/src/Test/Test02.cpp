/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test02.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 12:26:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int	test02(){
	msgTest(" Test interface ICharacter class Character ");

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances constructor default:\n");
	Debug::msg(3, ITALI, CYAN ,"Character *player = new Character();\n");
	Character *player = new Character();

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances copy constructor:\n");
	Debug::msg(3, ITALI, CYAN ,"ICharacter *ptrICharacter = new Character(*player);\n");
	ICharacter *ptrICharacter = new Character(*player);

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances constructor with name:\n");
	Debug::msg(3, ITALI, CYAN ,"Character *playerName = new Character(\"playerName\");\n");
	Character *playerName = new Character("playerName");

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances copy assignment constructor:\n");
	Debug::msg(3, ITALI, CYAN ,"Character *ptrPlayer = new Character();\n");
	Character *ptrPlayer = new Character();
	Debug::msg(3, ITALI, CYAN ,"*ptrPlayer = static_cast<Character&>(*ptrICharacter);\n");
	*ptrPlayer = static_cast<Character&>(*ptrICharacter);

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n\n   Destructor Character:\n");
	delete player;
	delete ptrICharacter;
	delete playerName ;
	delete ptrPlayer;
	return (0);
}
