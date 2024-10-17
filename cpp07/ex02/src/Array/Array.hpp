/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:42:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/17 15:16:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

typedef unsigned int uint;

template <typename T>
class Array{
	private:
		T*			_array;
		uint		_len;

	public:
		~Array();
		Array();
		Array(uint n);
		Array(Array const &orin);
		Array&operator=(Array const &orin);
		uint	size() const;
		T &operator[](const uint &index);
		const T &operator[](const uint &index) const;
};

#include "Array.tpp"

#endif