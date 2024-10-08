/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:50:06 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 10:35:35 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"

int Debug::stop = 1;

void	Debug::msg(int nbrArguments, ...){
	va_list	args;
	va_start(args, nbrArguments);
	
	for(int i = 0; i < nbrArguments; i++)
	{
		const char *str = va_arg(args, const char *);
		std::cout << str;
	}
	std::cout << RESET;
}

void	Debug::msgOrthodox(int nbr, ...)
{
	if (stop)
		return ;
	va_list	args;
	va_start(args, nbr);
	for(int i = 0; i < nbr; i++)
	{
		const char *str = va_arg(args, const char *);
		std::cout << str;
	}
	std::cout << RESET;
}
