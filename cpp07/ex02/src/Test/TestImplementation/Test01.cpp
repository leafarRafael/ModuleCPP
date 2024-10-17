/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/17 16:32:01 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "UnitTest.hpp"
#include "Array.hpp"
#include <string>
#include <fstream>
#include <ostream>


int	test01(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                    Test Array std::string\n");

	Array<std::string> myArray(30);
	std::ifstream infile("./fileTest01.txt");
	std::string line;
	try{
		for (int i = 0; i < 30; i++){
			std::getline(infile, line);
			myArray[i] = line;
			if (infile.eof())
				break ;
		}
		for (int i = 0; i < 30; i++){
			std::cout << myArray[i] << '\n';
		}
	}catch(std::exception &e){
		e.what();
		return (1);
	}
	infile.close();
	Debug::msg(1, DECLFORMAT);
	return 0;
}