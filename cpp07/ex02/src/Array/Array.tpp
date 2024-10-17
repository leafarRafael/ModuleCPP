/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:08:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/17 15:36:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <stdexcept>
#include "Array.hpp"

template <typename T>
Array<T>::~Array(){
	delete[] _array;
}

template <typename T>
Array<T>::Array():_array(NULL), _len(0){}

template <typename T>
Array<T>::Array(uint n):_array(new T[n]), _len(n){}

template <typename T>
Array<T>::Array(Array const &orin):_array(new T[orin._len]), _len(orin._len){
	_len = orin._len;
	if (_array)
		delete[] _array;
	_array = new T[orin._len];
	if (orin._array){
		for (uint i = 0; i < orin._len; i++){
			_array[i] = orin._array[i];
		}
	}
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &orin){
	if (this != &orin)
	{
		_len = orin._len;
		if (_array)
			delete[] _array;
		_array = new T[orin._len];
		if (orin._array){
			for (uint i = 0; i < orin._len; i++){
				_array[i] = orin._array[i];
			}
		}
	}
	return *this;
}

template <typename T>
uint	Array<T>::size() const{
	return _len;
}

template <typename T>
T &Array<T>::operator[](const uint &index){
	if (index >= _len)
		throw std::out_of_range("Exception: index is out of bounds.\n");
	return _array[index];
}

template <typename T>
const T &Array<T>::operator[](const uint &index) const{
	if (index >= _len)
		throw std::out_of_range("Exception: index is out of bounds.\n");
	return _array[index];
}

#endif