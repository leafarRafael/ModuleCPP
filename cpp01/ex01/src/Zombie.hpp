/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:58:57 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/16 15:09:32 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();
		void		setName(std::string name);
		void		announce(void);
};

#endif