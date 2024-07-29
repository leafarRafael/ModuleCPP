/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:52:24 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/27 17:14:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
 #define HARL_HPP

#include <string>

#define DEBUG "DEBUG"
#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO "INFO"
#define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING "WARNING"
#define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define ERROR "ERROR"
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

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
		void complain(std::string level);

};

typedef struct s_ptr
{
	std::string	input;
	void (Harl::*function)(void);

}	t_pointer;

#endif