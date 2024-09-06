/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:43:47 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/06 18:10:16 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap:public ClapTrap
{
	public:
		~FragTrap();
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &origin);
		FragTrap &operator=(const FragTrap &origin);
		void highFivesGuys();
};


#endif