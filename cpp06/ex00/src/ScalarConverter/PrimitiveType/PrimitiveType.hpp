/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrimitiveType.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:11:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 10:38:27 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVETYPE_HPP
#define PRIMITIVETYPE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>

class PrimitiveType{
	private:
			PrimitiveType();

	protected:
		virtual void			displayConversion(long double input);
		virtual void			validatePseudoLiterals(std::string input);
		virtual void			validateNumberFormat(std::string input);
		virtual void			validateEmptyInput(std::string input);
		virtual long double		extractNumericValue(u_int indexSignalPositive, u_int length, std::string input);
		virtual long double		parseStringToLongDouble(std::string input);
		virtual long double		handleSingleCharacterInput(long double doubleInput);
		virtual long double		validateNumericString(std::string input);

	public:
		virtual void	convertStringPrimitiveType(std::string input) = 0;
		~PrimitiveType(){};
	
	class PrimitiveTypeNonDisplayable:public std::exception{
		public:
			const char *what() const throw();
	};
	class PrimitiveTypeImpossible:public std::exception{
		public:
			const char *what() const throw();
	};	
};

#endif