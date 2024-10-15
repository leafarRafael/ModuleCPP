/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnitTest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:48:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 10:02:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITTEST_HPP
#define UNITTEST_HPP
#include <string>

class UnitTest{
	private:
		static int totalTest;
		UnitTest();

	public:
		static int	(*select_test(int i))();
		static int	getTotalTest();
};
std::string	getInputTest();
int			test00();

#endif