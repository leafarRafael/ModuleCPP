/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:04:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/23 17:23:10 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 #define FIXED_HPP

#include <ostream>


class Fixed
{
	private:
		int					_value;
		static const int	_bits;


	public:
	//methods
		int  getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

	//Constuct and destruct
		Fixed();
		Fixed(const int add_int);
		Fixed(const float add_float);
		Fixed(const Fixed &origin);
		Fixed &operator=(const Fixed &origin);
		~Fixed();

	//Orverload comparison operators
		bool operator<(Fixed & ref) const;
		bool operator<=(Fixed & ref) const;
		bool operator>(Fixed & ref) const;
		bool operator>=(Fixed & ref) const;
		bool operator==(Fixed & ref) const;
		bool operator!=(Fixed & ref) const;
	
	//Orverload arithmetic operators
		Fixed operator-(const Fixed & ref) const;
		Fixed operator+(const Fixed & ref) const;
		Fixed operator*(const Fixed & ref) const;
		Fixed operator/(const Fixed & ref) const;

	//Orverload increment/decrement
		Fixed &operator--();
		Fixed &operator++();
		Fixed operator--(int);
		Fixed operator++(int);
	
	//static member function
		static Fixed &min(Fixed & ref_A, Fixed & ref_B);
		static const Fixed &min(const Fixed & ref_A, const Fixed & ref_B);
		static Fixed &max(Fixed & ref_A, Fixed & ref_B);
		static const Fixed &max(const Fixed & ref_A, const Fixed & ref_B);
};

std::ostream &operator<<(std::ostream &stream, const Fixed &ref);

#endif