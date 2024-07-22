/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:58:57 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/16 10:54:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void		announce(void);
};


#endif