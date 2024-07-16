/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:13:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/15 09:59:01 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
};

Account::~Account( void ){};

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
};
int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

/* _accountIndex;
_amount;
_nbDeposits;
_nbWithdrawals; */