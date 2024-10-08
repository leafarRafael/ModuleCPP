/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test07.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/07 10:19:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "Form.hpp"
#include "Debug.hpp"

int	test07(){
	msgTest(" Test 07 ");

	Debug::msg(1, YELLOW ITALI SUBLI BOLD "\n   grade_sign and _grade_execute Margins: \n");
	try{
		Debug::msg(1, ITALI SUBLI CYAN "\n    Form A(\"form A\", 1, 1);\n");
		Form A("form A", 1, 1);
		std::cout << A << '\n';
	
		Debug::msg(1, ITALI SUBLI CYAN "\n    Form B(\"form B\", 150, 150);\n");
		Form B("form B", 150, 150);
		std::cout << B << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return 1;	
	}
	return (0);
}
