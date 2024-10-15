/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToInt.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:11:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 15:44:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOINT_HPP
#define TOINT_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <cerrno>

class ToInt{
	private:
		ToInt();
		~ToInt();
		ToInt(const ToInt &ref);
		ToInt&operator=(const ToInt &ref);
		static void	displayConversion(long input);
		static void	validatePseudoLiterals(std::string input);
		static void	validateNumberFormat(std::string input);
		static void	validateEmptyInput(std::string input);
		static long	parseStringToLongDouble(std::string input);
		static long	handleSingleCharacterInput(long doubleInput);
		static long	converStringToDouble(std::string input);
		static long	checkRange(long doubleInput);

	public:
		static void	convertStringToInt(std::string input);
	
	class ToIntNonDisplayable:public std::exception{
		public:
			const char *what() const throw();
	};
	class ToIntImpossible:public std::exception{
		public:
			const char *what() const throw();
	};	
};

#endif