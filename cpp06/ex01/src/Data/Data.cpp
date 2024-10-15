/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 08:23:18 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Debug.hpp"
#include "Color.hpp"


Data::~Data(){
	Debug::msgOrthodox(1, "destructor\n");
}

Data::Data():_name(""), _value(0), _lastName(""){
	Debug::msgOrthodox(1, "Constructor default\n");
}

Data::Data(std::string name, int value, std::string lastName):
_name(name), _value(value), _lastName(lastName){
	Debug::msgOrthodox(1, "Constructor with parameters\n");
}

Data::Data(const Data &ref){
	_name = ref.getName();
	_value = ref.getValue();
	_lastName = ref.getLastName();
	Debug::msgOrthodox(1, "Constructor copy default\n");
}

Data &Data::operator=(const Data &ref){
	if (this != &ref){
		_name = ref.getName();
		_value = ref.getValue();
		_lastName = ref.getLastName();
	}
	return *this;
}

void	Data::setName(std::string name){
	_name = name;
}

void	Data::setValue(int value){
	_value = value;
}

std::string	Data::getName() const{
	return _name;
}

int			Data::getValue() const{
	return _value;
}

void		Data::setLastName(std::string lastName){
	this->_lastName = lastName;
}

std::string	Data::getLastName() const{
	return std::string("");
}