/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:20:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/22 12:30:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):
_amount(initial_deposit)
{
	_displayTimestamp();
	_accountIndex = getNbAccounts();
	std::cout << "index:" << _accountIndex << ';'
		<< "amount:" << initial_deposit << ';'
		<< "created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_totalNbDeposits++;
};

Account::Account(){};

Account::~Account()
{
	_displayTimestamp();

	std::cout << "index" << _accountIndex << ';'
		<< "amount:" << _amount << ';'
		<< "closed" << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ';'
		<< "total:" << Account::getTotalAmount() << ';'
		<< "deposits:" << Account::getNbDeposits() << ';'
		<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}


void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
		<< "p_amount:" << _amount << ';'
		<< "deposit:" << deposit << ';';
		_amount += deposit;
		_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;
	std::cout << "amount:" << _amount << ';'
		<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
		<< "p_amount:" << _amount << ';'
		<< "withdrawal:";
	if (_amount > withdrawal)
	{
		std::cout << withdrawal << ';';
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals += _nbWithdrawals;
		std::cout << "amount:" << _amount << ';'
			<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (false);
	}
	else {
		std::cout << "refused\n";
	
	}
	return (true);
}

int		Account::checkAmount() const
{
	return (_totalAmount);
};

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
		<< "amount:" << _amount  << ';'
		<< "deposits:" << _nbDeposits  << ';'
		<< "withdrawals:" << _nbWithdrawals << std::endl;
};

void Account::_displayTimestamp()
{
	std::time_t time = std::time(NULL);

    std::cout << '[' << 1900 + std::localtime(&time)->tm_year << '/'
		<< '0' << std::localtime(&time)->tm_mon << '/'
		<< std::localtime(&time)->tm_mday << '_'
		<< std::localtime(&time)->tm_hour << ':'
		<< std::localtime(&time)->tm_min << ':'
		<< std::localtime(&time)->tm_sec << "] ";
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}
