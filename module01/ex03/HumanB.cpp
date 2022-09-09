/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:23:32 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/09 08:36:36 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
	: name(name), weapon(nullptr)
{
}

void HumanB::attack(void) const
{
	if (weapon != nullptr)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	else
	{
		std::cout << name << "cannot attack without a weapon" << std::endl;
	}
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
