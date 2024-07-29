/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:09:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/29 13:32:03 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_bits = 8;

//////////////////////Constructor///////////////////////////
Fixed::Fixed(): _value(0) {}

Fixed::Fixed(const int add_int): _value(add_int << _bits) {}

Fixed::Fixed(const float add_float): _value(roundf(add_float * (1 << _bits))){}

Fixed::Fixed(const Fixed &origin) {*this = origin;}

//////////////////////Overload copy assignment operator///////////
Fixed &Fixed::operator=(const Fixed &origin)
{
	this->setRawBits(origin._value);
	return (*this);
}

//////////////////////Destructor methods///////////////////////////
Fixed::~Fixed() {}

//////////////////////Conversion methods///////////////////////////
float Fixed::toFloat() const
{	return ((float)_value / (1 << Fixed::_bits));}

int Fixed::toInt() const
{	return (_value >> _bits); }

////////////////////// Methods getters setters ///////////////////////////
int Fixed::getRawBits() const
{	return (_value); }

void Fixed::setRawBits(int const raw)
{	_value = raw; }

////////////////////// Overload insertion operator ///////////////////////////
std::ostream &operator<<(std::ostream &stream, const Fixed &ref)
{
	stream << ref.toFloat();
	return (stream);
}

////////////////////// Overload Comparison operator ///////////////////////////
bool Fixed::operator<(Fixed & ref) const 
{	return (this->_value < ref.getRawBits());}

bool Fixed::operator<=(Fixed & ref) const
{	return (this->_value <= ref.getRawBits());}

bool Fixed::operator>(Fixed & ref) const
{	return (this->_value > ref.getRawBits());}

bool Fixed::operator>=(Fixed & ref) const
{	return (this->_value >= ref.getRawBits());}

bool Fixed::operator==(Fixed & ref) const
{	return (this->_value == ref.getRawBits());}

bool Fixed::operator!=(Fixed & ref) const
{	return (this->_value != ref.getRawBits());}

////////////////////// Overload Arithmetic operator ///////////////////////////
Fixed Fixed::operator-(const Fixed & ref) const
{	return (Fixed(this->toFloat() - ref.toFloat()));}

Fixed Fixed::operator+(const Fixed & ref) const
{	return (Fixed(this->toFloat() + ref.toFloat()));}

Fixed Fixed::operator*(const Fixed & ref) const
{	return (Fixed(this->toFloat() * ref.toFloat()));}

Fixed Fixed::operator/(const Fixed & ref) const
{	return (Fixed(this->toFloat() / ref.toFloat()));}

////////////////////// Incremente decrement prefix ///////////////////////////
Fixed& Fixed::operator--()
{
	--this->_value;
	return (*this);
}

Fixed& Fixed::operator++()
{
	++this->_value;
	return (*this);
}

////////////////////// Incremente decrement postfix //////////////////////
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	this->_value--;
	return (temp);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	this->_value++;
	return (temp);
}

////////////////////////static member function///////////////////////////
Fixed &Fixed::min(Fixed & ref_A, Fixed & ref_B)
{
	if (ref_A.getRawBits() < ref_B.getRawBits())
		return (ref_A);
	return (ref_B);
}

const Fixed &Fixed::min(const Fixed & ref_A, const Fixed & ref_B)
{
	if (ref_A.getRawBits() < ref_B.getRawBits())
		return (ref_A);
	return (ref_B);
}

Fixed &Fixed::max(Fixed & ref_A, Fixed & ref_B)
{
	if (ref_A.getRawBits() > ref_B.getRawBits())
		return (ref_A);
	return (ref_B);
}

const Fixed &Fixed::max(const Fixed & ref_A, const Fixed & ref_B)
{
	if (ref_A.getRawBits() > ref_B.getRawBits())
		return (ref_A);
	return (ref_B);
}
