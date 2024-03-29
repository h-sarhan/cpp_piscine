/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:47:20 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:32:55 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _contactsIdx(0) {}

void PhoneBook::addContact(void)
{
    std::string first;
    std::string last;
    std::string nick;
    std::string number;
    std::string secret;

    std::cout << "Enter first name: " << std::endl;
    std::getline(std::cin, first);
    std::cout << "Enter last name: " << std::endl;
    std::getline(std::cin, last);
    std::cout << "Enter nickname: " << std::endl;
    std::getline(std::cin, nick);
    std::cout << "Enter phone number: " << std::endl;
    std::getline(std::cin, number);
    std::cout << "Enter secret: " << std::endl;
    std::getline(std::cin, secret);
    _contacts[_contactsIdx] = Contact(first, last, nick, number, secret);
    _contactsIdx++;
    if (_contactsIdx == 8)
        _contactsIdx = 0;
}

void PhoneBook::_displayContacts(void) const
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "| Index | First Name | Last Name | Nickname |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (size_t i = 0; i < 8; i++)
    {
        _contacts[i].displayContactSummary(i);
    }
}

void PhoneBook::searchPhoneBook(void) const
{
    std::string contactIdxInput;
    int contactIdx;
    bool validInput = true;

    _displayContacts();
    std::cout << "Choose a contact" << std::endl;
    std::getline(std::cin, contactIdxInput);
    for (size_t i = 0; i < contactIdxInput.length(); i++)
    {
        if (!std::isdigit(contactIdxInput[i]))
        {
            validInput = false;
        }
    }
    std::istringstream(contactIdxInput) >> contactIdx;
    if (!std::cin || contactIdx < 0 || contactIdx >= 8 ||
        _contacts[contactIdx].getCreated() == false || validInput == false ||
        contactIdxInput.length() == 0)
    {
        std::cout << "Invalid contact" << std::endl;
    }
    else
    {
        _contacts[contactIdx].displayContactDetails();
    }
    std::cout << std::endl;
}
