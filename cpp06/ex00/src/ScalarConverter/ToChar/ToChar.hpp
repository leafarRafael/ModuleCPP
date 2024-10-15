/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToChar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:11:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 15:43:18 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOCHAR_HPP
#define TOCHAR_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cerrno>

class ToChar{
	private:
		ToChar();
		~ToChar();
		ToChar(const ToChar &ref);
		ToChar&operator=(const ToChar &ref);
		static void	displayConversion(int input);
		static void	validatePseudoLiterals(std::string input);
		static void	validateNumberFormat(std::string input);
		static void	validateEmptyInput(std::string input);
		static int	parseStringToLongDouble(std::string input);
		static int	handleSingleCharacterInput(int doubleInput);
		static int	converStringToDouble(std::string input);

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