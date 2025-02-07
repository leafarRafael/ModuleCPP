/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:02:02 by rbutzke           #+#    #+#             */
/*   Updated: 2025/02/03 15:29:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename swapVar>
void swap(swapVar *arg1, swapVar *arg2){
	swapVar temp = *arg1;
	*arg1 = *arg2;
	*arg2 = temp;
}

template <typename swapVar>
void swap(swapVar &arg1, swapVar &arg2){
	swapVar temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template <typename minVar>
const minVar	&min(const minVar &arg1, const minVar &arg2){
	return (arg1 < arg2) ? arg1 : arg2;
}

template <typename maxVar>
const maxVar	&max(const maxVar &arg1, const maxVar &arg2){
	return (arg1 > arg2) ? arg1 : arg2;
}

#endif