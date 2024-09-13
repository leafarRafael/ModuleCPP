/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test04.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 15:51:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

static void learnMateria(IMateriaSource *materia);
static void creatMateria(IMateriaSource *materia);

int test04(){
	msgTest(" Test Methods learnMateria(), createMateria() class MateriaSource ");

	Debug::msg(3, ITALI, CYAN ,"MateriaSource *materia = new MateriaSource();\n");
	IMateriaSource *materia = new MateriaSource();
	learnMateria(materia);
	creatMateria(materia);

	delete materia;
	return (0);
}

static void learnMateria(IMateriaSource *materia){
	Debug::msg(3, ITALI, CYAN ,"Ice *ice = new Ice();\n");
	Ice *ice = new Ice();
	Debug::msg(3, ITALI, CYAN ,"Cure *cure = new Cure();\n");
	Cure *cure = new Cure();

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   learnMateria():\n");
	Debug::msg(3, ITALI, CYAN ,"2 times materia->learnMateria(ice);\n");
	Debug::msg(3, ITALI, CYAN ,"2 times materia->learnMateria(cure);\n");
	materia->learnMateria(ice);
	materia->learnMateria(cure);
	materia->learnMateria(ice);
	materia->learnMateria(cure);
	Debug::msg(3, ITALI, CYAN ,"\nmateria->learnMateria(new Ice());\n");
	materia->learnMateria(new Ice());
	Debug::msg(3, ITALI, CYAN ,"\nmateria->learnMateria(new Cure());\n");
	materia->learnMateria(new Cure());
	Debug::msg(3, ITALI, CYAN ,"\nstatic_cast<MateriaSource*>(materia)->showMateria();\n");
	static_cast<MateriaSource*>(materia)->showMateria();
}

static void creatMateria(IMateriaSource *materia){
	AMateria *ptr;

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   creatMateria():\n");
	Debug::msg(3, ITALI, CYAN , "ptr = materia->createMateria(\"ice\");\n");
	ptr = materia->createMateria("ice");
	Debug::msg(4, ITALI, CYAN , "ptr->getType() = ", ptr->getType().c_str());
	delete ptr;
	
	Debug::msg(3, ITALI, CYAN , "\nptr = materia->createMateria(\"cure\");\n");
	ptr = materia->createMateria("cure");
	Debug::msg(4, ITALI, CYAN , "ptr->getType() = ", ptr->getType().c_str());
	delete ptr;
}