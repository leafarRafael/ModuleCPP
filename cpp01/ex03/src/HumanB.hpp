/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:44:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/17 08:02:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
 #define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;

	public:
		~HumanB();
		HumanB(std::string _name);
		HumanB();
		void	attack() const;
		void	setWeapon(Weapon & weapon);
};

#endif