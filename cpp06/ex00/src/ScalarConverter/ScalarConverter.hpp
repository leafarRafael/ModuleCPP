/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:47:15 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/13 13:54:16 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <sstream>

class ScalarConverter{
	private:
		ScalarConverter();
		~ScalarConverter();
		
	protected:
		static void	validInput(std::string input);

	public:
		static	void convert(std::string input);
};

#endif