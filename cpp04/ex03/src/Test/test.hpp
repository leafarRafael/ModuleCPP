/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/12 10:36:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
#include "Color.hpp"
#include "Debug.hpp"

#define NBR_TEST 7

void	msg_(std::string str, int format);
void	msgTest(std::string msg);
int		test00();
int		test01();
int		test02();
int		test03();
int		test04();
int		test05();
int		test06();

#endif