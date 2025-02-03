/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:37:01 by rbutzke           #+#    #+#             */
/*   Updated: 2025/02/03 12:40:41 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <utility>

template<typename cType, typename pairType>
void	PmergeMe::mergeInsertSort(cType &origin, pairType &pairs){
	if (origin.size() <= 1)
		return ;
	pairType	biggerSorted;
	cType 		bigger, smallest;

	createGroup(origin, pairs);
	sortPairGroup(pairs);
	sortPairsLargestElement(pairs.begin(), pairs.end(), biggerSorted);
	setBiggerSmallest(bigger, smallest, biggerSorted);
	biggerSorted.clear();
	mergeInsertSort(bigger, biggerSorted);
	insertSmallest(bigger, smallest);
	origin.clear();
	origin = bigger;
	if(origin[0] == -1)
		origin.erase(origin.begin(),origin.begin() + 1);
}

template<typename pairType>
void	PmergeMe::sortPairGroup(pairType &origin){
	typedef typename pairType::iterator	iter;

	for (iter it = origin.begin(); it != origin.end(); it++){
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

inline bool compare(const std::pair<int, int> &t, const int value){
	return (t.second < value);
}

template<typename iter, typename pairType>
void	PmergeMe::sortPairsLargestElement(iter it, iter ite, pairType &biggerSorted){
	if (it == ite)
		return ;
	biggerSorted.insert(std::lower_bound(biggerSorted.begin(), biggerSorted.end(), it->second, compare), *it);
	sortPairsLargestElement(it+1, ite, biggerSorted);
}

template<typename cType, typename pairType>
void	PmergeMe::setBiggerSmallest(cType &bigger, cType &smallest, pairType &pairs){
	typedef typename pairType::iterator iter;

	for(iter it = pairs.begin(); it != pairs.end(); it++){
		smallest.push_back(it->first);
		bigger.push_back(it->second);
	}
}

template<typename cType, typename pairType>
void	PmergeMe::createGroup(cType &origin, pairType &pairs){
	typedef typename cType::iterator iter;

	if (origin.size() %2 != 0)
		origin.push_back(-1);

	iter it = origin.begin();
	iter itnext = it+1;
	while (it != origin.end()){
		pairs.push_back(std::make_pair(*it, *itnext));
		it += 2, itnext += 2;
	}
}

template<typename cType>
void	PmergeMe::insertSmallest(cType &bigger, cType &smallest){
	bigger.insert(bigger.begin(), *smallest.begin());
	smallest.erase(smallest.begin(), smallest.begin() +1);
	while (smallest.size() != 0){
		bigger.insert(
			std::lower_bound(
				bigger.begin(), bigger.end(), *smallest.begin()
				), *smallest.begin());
		smallest.erase(smallest.begin(), smallest.begin()+1);
	}
}
