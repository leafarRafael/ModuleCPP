/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/16 15:44:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string		initialize = "HI THIS IS BRAIN";
	std::string*	stringPTR = &initialize;
	std::string&	stringREF = initialize;

	std::cout << &initialize << '\n';
	std::cout << stringPTR << '\n';
	std::cout << &stringREF << '\n';
	std::cout << initialize << '\n';
	std::cout << *stringPTR << '\n';
	std::cout << stringREF << '\n';
	return (0);
}
