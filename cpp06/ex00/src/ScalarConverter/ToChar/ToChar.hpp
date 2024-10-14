/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToChar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:11:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 10:46:27 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOCHAR_HPP
#define TOCHAR_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>

class ToChar{
	private:
		static void			displayConversion(long double input);
		static void			validatePseudoLiterals(std::string input);
		static void			validateNumberFormat(std::string input);
		static void			validateEmptyInput(std::string input);
		static long double	extractNumericValue(u_int indexSignalPositive, u_int length, std::string input);
		static long	double	parseStringToLongDouble(std::string input);
		static long double	handleSingleCharacterInput(long double doubleInput);
		static long double	validateNumericString(std::string input);

	public:
		static void	convertStringToChar(std::string input);
	
	class ToCharNonDisplayable:public std::exception{
		public:
			const char *what() const throw();
	};
	class ToCharImpossible:public std::exception{
		public:
			const char *what() const throw();
	};	
};

#endif