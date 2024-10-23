/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:02:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/23 09:04:26 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <list>
#include <vector>

template<typename Type, class ContainerBaseDefault = std::deque<Type> >
class MutantStack:public std::stack<Type, ContainerBaseDefault>{
	public:
		~MutantStack();
		MutantStack();
		MutantStack(const MutantStack &orin);
		MutantStack&operator=(const MutantStack &orin);

		typedef typename ContainerBaseDefault::iterator iterator;
		typedef typename ContainerBaseDefault::const_iterator const_iterator;
		const_iterator begin()const ;
		iterator begin();
		const_iterator end()const ;
		iterator end();
};

#include "MutantStack.tpp"

#endif