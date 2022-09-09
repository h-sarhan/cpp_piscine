/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 09:07:20 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/09 10:23:30 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Invalid arguments!!" << std::endl;
		return (EXIT_FAILURE);
	}
	const std::string fileName = argv[1];
	const std::string str1 = argv[2];
	const std::string str2 = argv[3];
	if (fileName.length() == 0)
	{
		std::cerr << "Invalid filename!!" << std::endl;
		return (EXIT_FAILURE);
	}
	if (str1.length() == 0)
	{
		std::cerr << "str1 cannot be empty!!" << std::endl;
		return (EXIT_FAILURE);
	}
	if (str1 == str2)
	{
		std::cerr << "str1 cannot be equal to str2!!" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string contents;
	char c;
	std::ifstream inStream(fileName);
	while (inStream.good())
	{
		inStream.get(c);
		if (inStream.good())
			contents.push_back(c);
	}
	inStream.close();
	if (contents.length() == 0)
	{
		std::ofstream outStream(fileName + ".replace");
		outStream.close();
		return (EXIT_SUCCESS);
	}
	while (contents.find(str1) != std::string::npos)
	{
		std::string before = contents.substr(0, contents.find(str1));
		std::string after = contents.substr(contents.find(str1) + str1.length(), contents.length());
		contents = before + str2 + after;
	}
	std::cout << contents;
	std::ofstream outStream(fileName + ".replace");
	outStream << contents;
	outStream.close();
	return (EXIT_SUCCESS);
}
