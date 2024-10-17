/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/17 15:51:16 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UnitTest.hpp"
#include "Debug.hpp"
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750

int	test00(){
	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n                         subject Test:\n");
	
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    
	for (int i = 0; i < MAX_VAL; i++){
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++){
        if (mirror[i] != numbers[i]){
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try{
        numbers[-2] = 0;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    try{
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++){
        numbers[i] = rand();
    }
    delete [] mirror;
	Debug::msg(1, DECLFORMAT);
	return 0;
}

