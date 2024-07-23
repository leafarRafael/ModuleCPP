/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:04:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/23 14:42:39 by rbutzke          ###   ########.fr       */
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

	//methods
	public:
		int  getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

	//Constuct and destruct
	public:
		Fixed();
		Fixed(const int add_int);
		Fixed(const float add_float);
		Fixed(const Fixed &origin);
		Fixed &operator=(const Fixed &origin);
		~Fixed();
};

std::ostream &operator<<(std::ostream &stream, const Fixed &ref);

#endif