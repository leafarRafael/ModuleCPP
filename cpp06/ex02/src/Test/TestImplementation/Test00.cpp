/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 11:05:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include <iostream>
#include "UnitTest.hpp"
#include "Functions.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <unistd.h>

int	test00(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                            Data Types:\n");
	Debug::stop = 0;
	{
		Base *base = generate();
		identify(base);
		delete base;
	}
	sleep(1);
	{
		Base *base = generate();
		identify(base);
		delete base;
	}
	sleep(1);
	{
		Base *base = generate();
		identify(base);
		delete base;
	}
	sleep(1);
	{
		Base *base = generate();
		identify(*base);
		delete base;
	}
	sleep(1);
	{
		Base *base = generate();
		identify(*base);
		delete base;
	}
	Debug::stop = 1;
	return (0);
}
