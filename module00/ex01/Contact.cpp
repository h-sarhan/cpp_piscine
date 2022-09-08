/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:34:13 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/07 02:04:40 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
	: created(false)
{
}

Contact::Contact(const std::string &firstName, const std::string &lastName,
				 const std::string &nickName, const std::string &phoneNumber,
				 const std::string &secret)
	: created(true), _firstName(firstName), _lastName(lastName), _nickName(nickName),
	  _phoneNumber(phoneNumber), _secret(secret)
{
}

Contact &Contact::operator=(const Contact &contact)
{
	this->_firstName = contact._firstName;
	this->_lastName = contact._lastName;
	this->_nickName = contact._nickName;
	this->_phoneNumber = contact._phoneNumber;
	this->_secret = contact._secret;
	this->created = contact.created;
	return (*this);
}

void Contact::displayContactSummary(size_t idx) const
{
	if (created == true)
	{
		std::cout << std::setw(10) << std::right;
		std::cout << idx << "|";
		std::cout << std::setw(10) << std::right;
		if (_firstName.length() > 10)
			std::cout << _firstName.substr(0, 9).append(".") << "|";
		else
			std::cout << _firstName << "|";
		std::cout << std::setw(10) << std::right;
		if (_lastName.length() > 10)
			std::cout << _lastName.substr(0, 9).append(".") << "|";
		else
			std::cout << _lastName << "|";
		std::cout << std::setw(10) << std::right;
		if (_nickName.length() > 10)
			std::cout << _nickName.substr(0, 9).append(".") << "|";
		else
			std::cout << _nickName << "|";
		std::cout << std::endl;
	}
}

void Contact::displayContactDetails(void) const
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickName << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Secret: " << _secret << std::endl;
}
