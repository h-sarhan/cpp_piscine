/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:23:32 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:55:29 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {}

void HumanB::attack(void) const
{
    if (_weapon != NULL)
    {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    }
    else
    {
        std::cout << _name << "cannot attack without a weapon" << std::endl;
    }
}

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }
