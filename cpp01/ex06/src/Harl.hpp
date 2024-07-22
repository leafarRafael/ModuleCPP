/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:52:24 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/19 14:58:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
 #define HARL_HPP

#include <string>

#define DEBUG "DEBUG"
#define INFO "INFO"
#define WARNING "WARNING"
#define ERROR "ERROR"

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();

	public:
		Harl();
		~Harl();
		void complain(std::string input);

};

typedef struct s_ptr
{
	std::string	input;
	void (Harl::*function)(void);

}	t_pointer;

typedef struct input
{
	std::string	input;
	int			index;

}	t_input;


#endif