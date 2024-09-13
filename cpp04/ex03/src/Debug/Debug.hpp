/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:45:44 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 10:35:35 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "Color.hpp"
#include <iostream>
#include <cstdarg>

class Debug
{
	public:
		static int stop;
		static void	msg(int nbrArgument, ...);
		static void	msgOrthodox(int nbr, ...);
};

#endif