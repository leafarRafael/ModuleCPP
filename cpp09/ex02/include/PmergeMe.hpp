/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:17:20 by rbutzke           #+#    #+#             */
/*   Updated: 2025/02/03 12:38:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <deque>
# include <vector>
# include <ctime>
# include <sstream>
# include <algorithm>
# include <cstdlib>

class PmergeMe{
	std::vector<int>					_vector;
	std::deque<int>						_deque;
	std::vector<std::pair<int, int> >	_vectorPair;
	std::deque<std::pair<int, int> > 	_dequePair;

	void 	printConteinerPair(std::deque<std::pair<int, int> > _dequePair);

	void	setConteiner(std::string &input);
	double	elapsedTime(double _startTime);
	void	normalize(std::string &input);
	bool	isNumeric(std::string &number);

	template<typename cType, typename pairType>
	void	mergeInsertSort(cType &origin, pairType &pairs);

	template<typename cType, typename pairType>
	void	createGroup(cType &origin,  pairType &pairs);

	template<typename pairType>
	void	sortPairGroup(pairType &origin);

	template<typename iter, typename pairType>
	void	sortPairsLargestElement(iter it, iter ite, pairType &biggerSorted);

	template<typename cType, typename pairType>
	void	setBiggerSmallest(cType &bigger, cType &smallest, pairType &pairs);

	template<typename cType>
	void	insertSmallest(cType &bigger, cType &smallest);

	template<typename cType>
	cType split(std::string &input, char delimiter);

	template<typename cType>
	void printConteiner(cType conteiner);

	template<typename cType>
	bool isSorted(cType conteiner);

	public:
		PmergeMe(std::string &input);
		~PmergeMe();
		PmergeMe&operator=(PmergeMe const &origin);
		PmergeMe(PmergeMe const &origin);
};

#include "Algorithm.tpp"
#include "Parse.tpp"
#include "utils.tpp"