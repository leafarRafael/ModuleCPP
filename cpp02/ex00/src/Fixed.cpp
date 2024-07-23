/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:09:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/23 10:44:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_fractional = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_integer = 0;
}

Fixed::Fixed(const Fixed &origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed &Fixed::operator=(const Fixed &origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(origin.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_integer);
}

void Fixed::setRawBits(int const raw)
{
	this->_integer = raw;
}