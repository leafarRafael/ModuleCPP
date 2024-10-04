/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:58:11 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/15 16:50:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

#define CHARACTER "\033[32mCharacter\033[0m"
#define MAX_SLOT_INVENTORY 4

class Character : public ICharacter
{
	private:
		AMateria*	_inventory[4];
		std::string	_name;

	// Helper methods
		void	_initMateria();
		void	_destroyMateria();
		void	_copyMateria(const Character & origin);

	public: 
	// Constructor, destructor, copy and copy assignment 
		std::string const & getName() const;
		~Character();
		Character();
		Character(std::string name);
		Character(const Character & origin);
		Character&operator=(const Character & origin);
		void	setName(std::string name);
		void	showInventory();

	// Override interface ICharacter
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif