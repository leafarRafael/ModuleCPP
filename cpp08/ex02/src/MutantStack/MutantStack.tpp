/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:02:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/23 08:57:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename Type, class ContainerBaseDefault>
MutantStack<Type, ContainerBaseDefault>::~MutantStack(){}

template<typename Type, class ContainerBaseDefault>
MutantStack<Type, ContainerBaseDefault>::MutantStack(){}

template<typename Type, class ContainerBaseDefault>
MutantStack<Type, ContainerBaseDefault>::MutantStack(const MutantStack &orin){*this = orin;}

template<typename Type, class ContainerBaseDefault>
MutantStack<Type, ContainerBaseDefault>&
MutantStack<Type, ContainerBaseDefault>::operator=(const MutantStack &orin){
	if (this != &orin){*this = orin;}
	return *this;
}

template<typename Type, class ContainerBaseDefault>
typename MutantStack<Type, ContainerBaseDefault>::const_iterator 
MutantStack<Type, ContainerBaseDefault>::begin()const {
	return this->c.begin();
}

template<typename Type, class ContainerBaseDefault>
typename MutantStack<Type, ContainerBaseDefault>::iterator
MutantStack<Type, ContainerBaseDefault>::begin(){
	return this->c.begin();
}

template<typename Type, class ContainerBaseDefault>
typename MutantStack<Type, ContainerBaseDefault>::const_iterator 
MutantStack<Type, ContainerBaseDefault>::end()const {
	return this->c.end();
}

template<typename Type, class ContainerBaseDefault>
typename MutantStack<Type, ContainerBaseDefault>::iterator 
MutantStack<Type, ContainerBaseDefault>::end(){
	return this->c.end();
}

