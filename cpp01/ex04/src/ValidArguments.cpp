/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValidArguments.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:41:56 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/30 10:24:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <filesystem>

static int	nbrArguments(int argc);
static int	typeArguments(char **argv);
int	msgError();

int	validArguments(int argc, char **argv)
{
	if (nbrArguments(argc))
		return (1);
	if (typeArguments(argv))
		return (1);
	return (0);
}

static int	nbrArguments(int argc)
{
	if (argc != 4)
		return (msgError());
	return (0);
}

static int	typeArguments(char **argv)
{
	if (!argv)
		return (1);
	if (argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
		return (msgError());
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
		return (msgError());
	return (0);
}

int	msgError()
{
	std::cerr << "Invalid arguments\n"
		<< "3 arguments are expected:\n"
		<< "Fist argument is file name;\n"
		<< "Second arguments is string to be replaced;\n"
		<< "fourth argument the new string.\n";
	return (1);
}
