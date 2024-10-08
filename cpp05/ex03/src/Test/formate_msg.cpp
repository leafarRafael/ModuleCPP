/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formate_msg.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:32:33 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/08 14:50:32 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Color.hpp"
#include "Debug.hpp"

void	msgTest(std::string msg)
{
	std::string lineup(msg.length() + (std::string(FORM).length() * 2), ' ');
	
	std::cout << '\n' << ITALI SUBLI BOLD MAGENTA << lineup << RESET << '\n';
	std::cout << '\n' 
		<< ITALI SUBLI MAGENTA FORM
		<< msg
		<< FORM RESET
		<< std::endl;
}

void	msg_(std::string str, int format)
{
	if (format == 1)
	{
		std::cout
			<< '\n'
			<< SUBLI
			<< ITALI
			<< str
			<< "\n\n"
			<< RESET;
		
	}
	if (format == 2)
	{
		std::cout
		<< BOLD
		<< ITALI
		<< str
		<< RESET
		<< "\n";
	}
}

std::string getName()
{
	extern char **_environ;
	std::string name;
	
	for (int i = 0; _environ[i]; i++)
	{
		std::string var(_environ[i]);
		if (var.find("USER=") != std::string::npos){
			name = var;
			break ;
		}
	}
	return (name.substr(5));
}