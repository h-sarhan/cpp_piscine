/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:14:35 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/09 08:36:42 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
#define HUMAN_B

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(const std::string &name);
	void attack(void) const;
	void setWeapon(Weapon& weapon);
private:
	const std::string name;
	Weapon *weapon;
};

#endif