/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:58:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/14 17:43:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include "Debug.hpp"
#include "Color.hpp"

uintptr_t	Serialization::serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* 		Serialization::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}

Serialization::Serialization(){}
Serialization::~Serialization(){}
Serialization::Serialization(const Serialization &ref){*this = ref;}
Serialization&Serialization::operator=(const Serialization &ref){
	if (this != &ref)
		*this = ref;
	return *this;
}
