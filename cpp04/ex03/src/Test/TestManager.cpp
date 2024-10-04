/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/15 15:35:58 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int (*select_test(int i))();

int	testManager(){
	for(int i = 0; i < NBR_TEST; i++)
		(*select_test(i))();
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
		};
	return (function[i]);
}
