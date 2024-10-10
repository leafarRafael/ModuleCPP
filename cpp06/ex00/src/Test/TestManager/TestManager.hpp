/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:50:06 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/09 18:59:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTMANAGER_HPP
# define TESTMANAGER_HPP

#include <string>

class UnitTest;

class TestManager {
	private:
		static void	specific();
		static void	menuOptions(std::string &option);
		static int	runAllTest();
		static int	runSpecificTest(int value);
		static void	generalStatus(int successTest, int totalTests);

	public:
		static void	options();
		
};

#endif