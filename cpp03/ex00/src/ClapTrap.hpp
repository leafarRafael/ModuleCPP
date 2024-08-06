/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:04:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/05 14:12:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		~ClapTrap();
		ClapTrap();
		ClapTrap(const ClapTrap & origin);
		ClapTrap &operator=(const ClapTrap & origin);
		ClapTrap(std::string _name);

		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		std::string			getName() const;
		int					getHitPoints() const;
		int					getEnergyPoints() const;
		int					getAttackDamage() const;
		void				setName(std::string target);
		void				setHitPoints(int hitPoints);
		void				setEnergyPoints(int energyPoints);
		void				setAttackDamage(int attackDamage);

};

#endif