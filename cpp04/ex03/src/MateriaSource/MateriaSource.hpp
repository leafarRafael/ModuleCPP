/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:33:36 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 12:23:50 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

#define MAX_NBR_MATERIA_SOURCE 4
#define MATERIASOURCE "MateriaSource"
class AMateria;


class MateriaSource:public IMateriaSource
{
	private:
		AMateria *_materiaSource[4];
		
	// Helper methods
		void	_initMateriaSource();
		void	_destroyMateriaSource();
		void	_copyMateriaSource(const MateriaSource & origin);

	public:
		~MateriaSource();
		MateriaSource();	
		MateriaSource(const MateriaSource & origin);
		MateriaSource&operator=(const MateriaSource & origin);
		void	showMateria();


	// Override
		void learnMateria(AMateria* origin);
		AMateria* createMateria(std::string const & type);
};

#endif