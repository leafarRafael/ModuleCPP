/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToInt.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:11:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 10:15:36 by rbutzke          ###   ########.fr       */
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

class ToInt{
	private:
		static void			displayConversion(long double input);
		static void			validatePseudoLiterals(std::string input);
		static void			validateNumberFormat(std::string input);
		static void			validateEmptyInput(std::string input);
		static long double	extractNumericValue(u_int indexSignalPositive, u_int length, std::string input);
		static long	double	parseStringToLongDouble(std::string input);
		static long	double	handleSingleCharacterInput(long double doubleInput);
		static long double	validateNumericString(std::string input);
	
		static long double	checkRange(long double doubleInput);

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