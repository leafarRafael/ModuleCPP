/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/17 10:31:58 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>

int	main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Error: could not open file.\n";
		return 1;
	}
	try{
		BitcoinExchange bit(av[1]);
	}catch(std::exception &e){
		std::cout << "Error: " << e.what() << "\n";
	}
	return 0;
}