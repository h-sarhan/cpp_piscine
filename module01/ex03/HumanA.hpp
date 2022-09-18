/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:14:35 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:52:33 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
public:
    HumanA(const std::string &name, Weapon &weapon);
    void attack(void) const;
    void setWeapon(const Weapon &weapon);

private:
    const std::string _name;
    Weapon &_weapon;
};

#endif