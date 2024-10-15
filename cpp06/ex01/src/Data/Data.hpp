/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:47:15 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 08:15:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data{
	private:
		std::string _name;
		int			_value;
		std::string _lastName;

	public:
		Data();
		Data(const Data &ref);
		Data(std::string name, int value, std::string lastName);
		Data&operator=(const Data &ref);
		~Data();
	
		void	setName(std::string name);
		void	setValue(int value);
		void	setLastName(std::string lastName);
		std::string	getName() const;
		std::string	getLastName() const;
		int			getValue() const;

};



#endif