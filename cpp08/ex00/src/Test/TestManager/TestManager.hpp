/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:50:06 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/12 14:48:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTMANAGER_HPP
# define TESTMANAGER_HPP

#include <string>

class UnitTest;

class TestManager {
	private:
		static int			getOptionSelection();
		static void			displayOptions();
		static int			runAllTest();
		static int			runSpecificTest(int index);
		static void			specific();
		static void			displayTestName(std::string test, std::string color);
		static int			validateTestSelection(std::string choiceInput);
		static void			displayTestStatus(int successTest, int totalTests);
		static std::string	formatTestName(int value);
		static std::string	getInput();
		static int			displayUnitStatus(int respost);
		static std::string	formateStatus(int value, std::string msg, std::string color);

	public:
		static void	showOptions();
		
};

#endif