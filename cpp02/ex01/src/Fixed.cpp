/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:09:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/23 12:36:38 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int add_int):
_value(add_int << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float add_float):
_value(roundf(add_float * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed &Fixed::operator=(const Fixed &origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(origin._value);
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat() const
{
	return ((float)_value / (float)(1 << Fixed::_bits));
	return (_value);
}

int Fixed::toInt() const
{
	return (_value >> _bits);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &ref)
{
	stream << ref.toFloat();
	return (stream);
}