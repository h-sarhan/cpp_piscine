/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:14:35 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:55:05 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
#define HUMAN_B

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
public:
    HumanB(const std::string &name);
    void attack(void) const;
    void setWeapon(Weapon &weapon);

private:
    const std::string _name;
    Weapon *_weapon;
};

#endif