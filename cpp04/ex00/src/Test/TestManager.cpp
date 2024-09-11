/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 08:56:22 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int (*select_test(int i))();

int	testManager(){
	int 		value_status;
	std::string	msg_status;

	for(int i = 0; i < NBR_TEST; i++)
	{
		value_status = 0;
		msg_status = OK;
		value_status = (*select_test(i))();
		if (value_status)
			msg_status = FAILED;
		std::cout << STATUS << msg_status;
	}
	std::cout << std::endl;
	return 0;
}

int (*select_test(int i))(){
	int	(*function[8])() = {
		test00,
		test01,
		test02,
		test03,
		test04,
		test05,
		test06,
		test07,
		};
	return (function[i]);
}
