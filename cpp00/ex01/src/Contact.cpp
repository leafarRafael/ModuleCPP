/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:18:06 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/14 12:07:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact():
_firstName(""), _lastName(""), _nickName(""),
_phoneNumber(""), _darkestSecret("") {};

Contact::Contact(std::string FName, std::string LName,
std::string NName, std::string PNbr, std::string DScrt):
_firstName(FName), _lastName(LName),
_nickName(NName), _phoneNumber(PNbr),
_darkestSecret(DScrt) {};


std::string Contact::getFirstName()
{
	return (_firstName);
}
std::string Contact::getLastName()
{
	return (_lastName);
}
std::string Contact::getNickName()
{
	return (_nickName);
}
std::string Contact::getPhoneNumber()
{
	return (_phoneNumber);
}
std::string Contact::getDarkestSecret()
{
	return (_darkestSecret);
}
void Contact::setFirstName(std::string FName)
{
	_firstName = FName;
}
void Contact::setLastName(std::string LName)
{
	_lastName = LName;
}
void Contact::setNickName(std::string NName)
{
	_nickName = NName;
}
void Contact::setPhoneNumber(std::string PNbr)
{
	_phoneNumber = PNbr;
}
void Contact::setDarkestSecret(std::string DScrt)
{
	_darkestSecret = DScrt;
}