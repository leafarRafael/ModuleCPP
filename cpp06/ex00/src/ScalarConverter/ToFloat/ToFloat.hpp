/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToFloat.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:11:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 10:12:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOFLOAT_HPP
#define TOFLOAT_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <limits>
#include <cfloat>
#include <iomanip>

class ToFloat{
	private:
		static void			displayConversion(long double input);
		static long double	validatePseudoLiteral(std::string input);
		static void			validateNumberFormat(std::string input);
		static void			validateEmptyInput(std::string input);
		static long double	extractNumericValue(u_int indexSignalPositive, u_int length, std::string input);
		static long	double	parseStringToLongDouble(std::string input);
		static long double	handleSingleCharacterInput(long double doubleInput);
		static long double	validateNumericString(std::string input);

		static int 			_precision;
		static void			setPrecision(std::string input);
	public:
		static void	convertStringToFloat(std::string input);
	
	class ToFloatNonDisplayable:public std::exception{
		public:
			const char *what() const throw();
	};
	class ToFloatImpossible:public std::exception{
		public:
			const char *what() const throw();
	};	
};

#endif