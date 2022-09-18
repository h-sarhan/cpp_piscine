/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:28:53 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:33:15 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
#define CONTACT

#include <iomanip>
#include <iostream>
#include <string>

class Contact
{
public:
    Contact(void);
    Contact(const std::string &firstName, const std::string &lastName,
            const std::string &nickName, const std::string &phoneNumber,
            const std::string &secret);
    Contact &operator=(const Contact &contact);
    void displayContactSummary(size_t idx) const;
    void displayContactDetails(void) const;

    bool getCreated(void) const;

private:
    bool _created;
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _secret;
};

#endif
