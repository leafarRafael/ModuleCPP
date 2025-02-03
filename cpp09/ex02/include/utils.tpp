/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:25:46 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/31 15:03:03 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename cType>
void PmergeMe::printConteiner(cType conteiner){
	typename cType::iterator it = conteiner.begin();

	for(; it != conteiner.end(); it++){
		std::cout << *it << ' ';
	}
	std::cout << '\n';
}

template<typename cType>
bool	PmergeMe::isSorted(cType conteiner){
	typename cType::iterator it, itnext;

	it = conteiner.begin();
	itnext = it +1;
	for(; itnext != conteiner.end(); it++){
		if (*it > *itnext)
			return false;
		itnext++;
	}
	return true;
}

