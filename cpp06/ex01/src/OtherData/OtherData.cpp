/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OtherData.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 07:39:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OtherData.hpp"
#include "Debug.hpp"
#include "Color.hpp"


OtherData::~OtherData(){}
OtherData::OtherData():_name(""), _value(0), _lastName(0){}
OtherData::OtherData(const OtherData &ref){
	_name = ref.getName();
	_value = ref.getValue();
	_lastName = ref.getLastName();
}
OtherData &OtherData::operator=(const OtherData &ref){
	if (this != &ref){
		_name = ref.getName();
		_value = ref.getValue();
	}
	return *this;
}

void	OtherData::setName(std::string name){
	_name = name;
}

void	OtherData::setValue(int value){
	_value = value;
}

std::string	OtherData::getName() const{
	return _name;
}

int			OtherData::getValue() const{
	return _value;
}

char	*OtherData::getLastName() const{
	return _lastName;
}

void	OtherData::setLastName(char *lastName){
	this->_lastName = lastName;
}