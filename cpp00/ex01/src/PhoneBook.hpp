/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:44:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/14 18:41:39 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
 #define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contact[8];
		int		_index;
		void 	fullContact(int index);
		void	allContact(int index);
		void	putContact(int index);

	public:
		int		addContact(int & index);
		void	searchContact(int index);
		void	exitProgram();
};

#endif