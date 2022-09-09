/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:14:35 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/09 08:30:10 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(const std::string &name, Weapon &weapon);
	void attack(void) const;
	void setWeapon(const Weapon& weapon);
private:
	const std::string name;
	Weapon &weapon;
};

#endif