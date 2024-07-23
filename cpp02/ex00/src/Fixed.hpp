/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:04:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/23 10:42:45 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 #define FIXED_HPP

class Fixed
{
	private:
		int					_integer;
		static const int	_fractional;

	public:
		Fixed();
		Fixed(const Fixed &origin);
		Fixed &operator=(const Fixed &origin);
		~Fixed();


		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif