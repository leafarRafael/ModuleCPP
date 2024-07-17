/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:00:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/07/17 16:08:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <fstream>
#include <iostream>
#include <string>

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
	replace(str, input[1], input[2]);
	if (input[1] == input[2])
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
	std::cout << file.find(orin);

	if (file.find(orin) == std::string::npos)
		std::cout << "DEU RUIM" << '\n';
/* 	if (file.find(orin))
	{
		file.replace(file.find(orin), orin.length(), newstr);
	}
	std::cout << file << '\n'; */
	//replace(file, orin, newstr);
}