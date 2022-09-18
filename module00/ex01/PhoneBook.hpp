/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:25:24 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:21:14 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK
#define PHONE_BOOK

#include "Contact.hpp"
#include <iostream>
#include <sstream>

class PhoneBook
{
public:
    PhoneBook(void);
    void addContact(void);
    void searchPhoneBook(void) const;

private:
    void _displayContacts(void) const;
    Contact _contacts[8];
    size_t _contactsIdx;
};
#endif
