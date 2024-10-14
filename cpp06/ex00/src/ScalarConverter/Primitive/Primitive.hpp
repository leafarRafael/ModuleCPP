/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Primitive.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:11:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 13:15:26 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include "ScalarConverter.hpp"

class Primitive{
	public:
		void 			convertStringPrimitive(std::string input);
		void			displayConversion(long double input);
		void			validatePseudoLiterals(std::string input);
		void			validateNumberFormat(std::string input);
		void			validateEmptyInput(std::string input);
		long double	extractNumericValue(u_int indexSignalPositive, u_int length, std::string input);
		long double	parseStringToLongDouble(std::string input);
		long double	handleSingleCharacterInput(long double doubleInput);
		long double	validateNumericString(std::string input);
	
	class PrimitiveNonDisplayable:public std::exception{
		public:
			const char *what() const throw();
	};
	class PrimitiveImpossible:public std::exception{
		public:
			const char *what() const throw();
	};	
};

#endif