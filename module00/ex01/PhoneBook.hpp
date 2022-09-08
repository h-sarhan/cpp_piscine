/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:25:24 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/07 02:01:42 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK
#define PHONE_BOOK

#include "Contact.hpp"
#include <iostream>

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
