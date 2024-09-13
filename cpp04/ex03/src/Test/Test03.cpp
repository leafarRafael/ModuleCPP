/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test03.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 12:27:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int test03(){
	msgTest(" Test interface IMateriaSource class MateriaSource ");

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances constructor default:\n");
	Debug::msg(3, ITALI, CYAN ,"MateriaSource *materia = new MateriaSource();\n");
	MateriaSource *materia = new MateriaSource();

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances copy constructor:\n");
	Debug::msg(3, ITALI, CYAN ,"IMateriaSource *ptrMateria = new MateriaSource(*materia);\n");
	IMateriaSource *ptrMateria = new MateriaSource(*materia);

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n   Instances copy assignment constructor:\n");
	Debug::msg(3, ITALI, CYAN ,"MateriaSource *ptr = new MateriaSource();\n");
	MateriaSource *ptr = new MateriaSource();
	Debug::msg(3, ITALI, CYAN ,"*ptr = *materia;\n");
	*ptr = *materia;


	materia->showMateria();
	ptr->showMateria();
	static_cast<MateriaSource*>(ptrMateria)->showMateria();

	Debug::msg(5, YELLOW, ITALI, SUBLI, BOLD, "\n\n      Destructor:\n");
	delete materia;
	delete ptrMateria;
	delete ptr;
	return (0);
}
