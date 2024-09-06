/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:12:19 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/06 13:57:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap:public ClapTrap
{
	public:
		~ScavTrap();
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap & origin);
		ScavTrap &operator=(const ScavTrap & origin);
		void attack(const std::string& target);
		void guardGate();
};

#endif