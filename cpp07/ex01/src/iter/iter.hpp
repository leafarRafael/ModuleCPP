/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:02:02 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 15:47:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <cctype>
#include <iostream>

template <typename TFirstArg, typename TreturnFunc, typename TargFunc>
void	iter(TFirstArg *c, size_t len, TreturnFunc (*f)(TargFunc &)){
	for (size_t i = 0; i < len; i++)
		f(c[i]);
}

template <typename TFirstArg, typename TreturnFunc, typename TargFunc>
void	iter(TFirstArg *c, size_t len, TreturnFunc (*f)(TargFunc)){
	for (size_t i = 0; i < len; i++)
		f(c[i]);
}

template <typename TFirstArg, typename TreturnFunc, typename TargFunc>
void	iter(TFirstArg *c, size_t len, TreturnFunc (*f)(TargFunc *)){
	for (size_t i = 0; i < len; i++)
		f(c[i]);
}


#endif