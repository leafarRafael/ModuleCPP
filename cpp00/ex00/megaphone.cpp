/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:04:25 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/14 10:13:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int x = 0; argv[i][x]; x++)
			std::cout << static_cast<char> (std::toupper(static_cast <unsigned char> (argv[i][x])));
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}