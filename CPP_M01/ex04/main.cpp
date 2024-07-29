/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:09:14 by rluari            #+#    #+#             */
/*   Updated: 2024/03/08 20:49:07 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	ft_doReplace(std::ifstream &inputFile, std::ofstream &outputFile, std::string s1, std::string s2)
{
	std::string str;
	char	c;

	while(!inputFile.eof() && inputFile >> std::noskipws >> c)
		str += c;
	int	i = 0;
    while (i < (int)str.size())
	{
        size_t found_pos = str.find(s1, i);
		if (i == (int)found_pos)
		{
			outputFile << s2;
			i += s1.size();
		}
		else
		{
			outputFile << str[i];
			i++;
		}
    }
}

bool	ft_parse(char **argv,  std::string &s1, std::string &s2)
{
	std::ifstream	inputFile(argv[1]);

	if (inputFile.fail())
	{
		std::cout << "Error: file not found" << std::endl;
		return true;
	}
	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return true;
	}
	std::string inputFileName = argv[1];
	std::string outputFileName = inputFileName + ".replace";
	std::ofstream outputFile(outputFileName.c_str());
    if (!outputFile.is_open())
	{
        std::cerr << "Error creating file!" << std::endl;
        return true;
    }
	ft_doReplace(inputFile, outputFile, s1, s2);
	inputFile.close();
	outputFile.close();
	return false;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (ft_parse(argv, s1, s2))
		return 1;
	return 0;
}