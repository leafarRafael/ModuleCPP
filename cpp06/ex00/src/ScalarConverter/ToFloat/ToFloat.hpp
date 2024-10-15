/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToFloat.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:11:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 15:43:56 by rbutzke          ###   ########.fr       */
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
#include <cerrno>

class ToFloat{
	private:
		ToFloat();
		~ToFloat();
		ToFloat(const ToFloat &ref);
		ToFloat&operator=(const ToFloat &ref);
		static void		displayConversion(float input);
		static float	validatePseudoLiteral(std::string input);
		static void		validateNumberFormat(std::string input);
		static void		validateEmptyInput(std::string input);
		static float	parseStringToLongDouble(std::string input);
		static float	handleSingleCharacterInput(float doubleInput);
		static float	converStringToDouble(std::string input);

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