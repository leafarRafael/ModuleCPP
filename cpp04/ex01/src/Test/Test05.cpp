/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test05.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 11:33:50 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "test.hpp"


int test05(){
 
	msgTest(" Testes mothods orthodox Brain class ");
	msg_("Instances Brain class:", 1);

	msg_("Brain small;", 2);
	Brain small;
	msg_("Brain big(small);", 2);
	Brain big(small);
	msg_("Brain noBrain = big;", 2);
	Brain noBrain = big;

	msg_("Destructor Brain class:", 1);
	return (0);
}
