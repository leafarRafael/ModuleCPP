/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 16:58:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestManager.hpp"
#include <string>
#include "Debug.hpp"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::string arg = argv[1];
		if (arg == "DEBUG")
			Debug::stop = 1;
	}
	testManager();
	return 0;
}
