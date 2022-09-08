/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:53:31 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/06 23:09:24 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int arg_idx = 1; arg_idx < argc; arg_idx++)
		{
			std::string arg = argv[arg_idx];
			for (size_t i = 0; i < arg.length(); i++)
			{
				std::cout << static_cast<char>(std::toupper(arg[i]));
			}
		}
		std::cout << std::endl;
	}
}
