/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:37:33 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/09 18:19:19 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string filter;

	if (argc != 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	filter = argv[1];
	switch (Harl::strToLogType(filter))
	{
	case Harl::DEBUG:
		harl.complain("DEBUG");
	case Harl::INFO:
		harl.complain("INFO");
	case Harl::WARNING:
		harl.complain("WARNING");
	case Harl::ERROR:
		harl.complain("ERROR");
		break;
	default:
		harl.complain("INVALID");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
