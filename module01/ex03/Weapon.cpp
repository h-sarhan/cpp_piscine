/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:11:25 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/09 08:19:25 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
	: type(type)
{
}

const std::string &Weapon::getType() const
{
	const std::string &typeRef = type;
	return (typeRef);
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
}
