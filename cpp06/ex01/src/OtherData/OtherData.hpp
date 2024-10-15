/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OtherData.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:47:15 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 07:38:15 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHERDATA_HPP
#define OTHERDATA_HPP

#include <iostream>

class OtherData{
	private:
		std::string _name;
		int			_value;
		char		*_lastName;

	public:
		OtherData();
		OtherData(const OtherData &ref);
		OtherData&operator=(const OtherData &ref);
		~OtherData();
	
		void	setName(std::string name);
		void	setLastName(char *lastName);
		void	setValue(int value);
		std::string	getName() const;
		char	*getLastName() const;
		int			getValue() const;

};



#endif