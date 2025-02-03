/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:24:32 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/31 14:52:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>

template<typename cType>
cType PmergeMe::split(std::string &input, char delimiter){
	cType		conteiner;
	std::string			token;
	std::istringstream	iss(input);
	long long			value = 0;

	if (input.empty())
		return conteiner;
	if (input.find(delimiter) == std::string::npos){
		if (not isNumeric(input))
			throw (std::runtime_error("Error: Input not numeric: " + input));
		value = std::atoi(input.c_str());
		if (value < 0)
			throw (std::runtime_error("Error: Is negative number: " + input));
		conteiner.push_back(value);
		return conteiner;
	}
	while (std::getline(iss, token, delimiter)){
		if (!token.empty()) {
			if (not isNumeric(token))
				throw (std::runtime_error("Error: Input not numeric: " + token));
			value = std::atoll(token.c_str());
			if (value > std::numeric_limits<int>::max())
				throw (std::runtime_error("Error: value greater than int max: " + token));
			if (value < 0)
				throw (std::runtime_error("Error: Is negative number: " + token));
			conteiner.push_back(value);
		}
	}
	return conteiner;
}