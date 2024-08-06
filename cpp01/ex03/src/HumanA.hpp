/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:31:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/31 10:58:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
 #define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon&		_weapon;

	public:
		HumanA(std::string _name, Weapon & _weapon);
		~HumanA();
		void	attack() const;

};

#endif