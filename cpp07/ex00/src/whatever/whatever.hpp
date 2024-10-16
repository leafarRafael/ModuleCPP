/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:02:02 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/15 13:33:32 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename swapVar>
void swap(swapVar *arg1, swapVar *arg2){
	swapVar temp;

	temp = *arg1;
	*arg1 = *arg2;
	*arg2 = temp;

}

template <typename minVar>
minVar	min(minVar arg1, minVar arg2){
	return (arg1 < arg2) ? arg1 : arg2;
}

template <typename maxVar>
maxVar	max(maxVar arg1, maxVar arg2){
	return (arg1 > arg2) ? arg1 : arg2;
}

#endif