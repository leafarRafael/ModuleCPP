/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:33:36 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/11 18:43:52 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>

#define MAX_MATERIA 4
class AMateria;

class MateriaSource:public IMateriaSource
{
	private:
		AMateria *_materia[4];
		
	// Helper methods
		void	_initMateria();
		void	_destroyMateria();
		void	_copyMateria(const Character & origin);

	public:
		~MateriaSource();
		MateriaSource();	
		MateriaSource(const MateriaSource & origin);
		MateriaSource&operator=(const MateriaSource & origin);


	// Override
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};