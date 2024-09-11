/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 17:16:55 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
#include "Color.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define NBR_TEST 10

void	msg_(std::string str, int format);
void	msgTest(std::string msg);
int		test00();
int		test01();
int		test02();
int		test03();
int		test04();
int		test05();
int		test06();
int		test07();
int		test08();
int		test09();

#endif