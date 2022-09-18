/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:36:00 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:22:41 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

static void displayPrompt(void)
{
    std::cout << "Enter a command" << std::endl;
    std::cout << "1. ADD" << std::endl
              << "2. SEARCH" << std::endl
              << "3. EXIT" << std::endl;
}

int main(void)
{
    std::string command;
    PhoneBook phoneBook;

    displayPrompt();
    std::getline(std::cin, command);
    while (command != "EXIT" && std::cin)
    {
        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        if (command == "SEARCH")
        {
            phoneBook.searchPhoneBook();
        }
        displayPrompt();
        std::getline(std::cin, command);
    }
}
