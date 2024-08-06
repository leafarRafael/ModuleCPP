/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/31 08:49:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include "ValidArguments.hpp"

std::string 	cpyFile(const char *input);
int				validArguments(int argc, char **argv);
void			cpyArguments(int argc, char **argv, std::string	input[3]);
void			replace(std::string & file, std::string orin, std::string newstr);

int main(int argc, char **argv)
{
	std::string		input[3];
	std::string		newFile;
	std::string		str;

	if (validArguments(argc, argv))
		return (1);
	cpyArguments(argc, argv, input);
	str = cpyFile(input[0].c_str());
	newFile = input[0] + ".replace";
	std::ofstream outfile(newFile.c_str());
	if (!outfile.is_open())
		return (msgError());
	if (input[1] != input[2])
		replace(str, input[1], input[2]);
	outfile << str;
	outfile.close();
	return 0;
}

void	cpyArguments(int argc, char **argv, std::string	input[3])
{
	int	x;

	x = 0;
	for(int i = 1; i <  argc; i++)
		input[x++] = std::string(argv[i]);
}

std::string cpyFile(const char *input)
{
	std::string		file;
	std::string		str;
	std::ifstream	infile;

	infile.open(input);
	while (std::getline(infile, str))
	{
		file.append(str);
		file.append("\n");
	}
	infile.close();
	return (file);
}

void	replace(std::string & file, std::string orin, std::string newstr)
{
	size_t	reFind;

	reFind = file.find(orin);
	if (reFind == std::string::npos)
		return ;
	file.erase(reFind, orin.length());
	file.insert(reFind, newstr);
	replace(file, orin, newstr);
}