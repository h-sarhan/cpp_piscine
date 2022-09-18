/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:37:33 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 08:28:21 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void harlFilter(const std::string &filter)
{
    Harl harl;

    switch (Harl::strToLogType(filter))
    {
    case Harl::DEBUG:
        harl.complain("DEBUG");
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        break;
    case Harl::INFO:
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        break;
    case Harl::WARNING:
        harl.complain("WARNING");
        harl.complain("ERROR");
        break;
    case Harl::ERROR:
        harl.complain("ERROR");
        break;
    default:
        harl.complain("INVALID");
        std::exit(EXIT_FAILURE);
    }
    std::exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments" << std::endl;
        return (EXIT_FAILURE);
    }
    harlFilter(argv[1]);
}
