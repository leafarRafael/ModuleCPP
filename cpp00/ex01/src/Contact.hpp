/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:18:11 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/14 12:07:52 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
 #define CONTACT_CPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		Contact(std::string FName, std::string LName, std::string NName, std::string PNbr, std::string DScrt);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		void		setFirstName(std::string FName);
		void		setLastName(std::string LName);
		void		setNickName(std::string NName);
		void		setPhoneNumber(std::string PNbr);
		void		setDarkestSecret(std::string DScrt);
};

#endif