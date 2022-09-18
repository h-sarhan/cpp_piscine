/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:23:32 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:52:52 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon) {}

void HumanA::attack(void) const
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

void HumanA::setWeapon(const Weapon &weapon) { _weapon = weapon; }
