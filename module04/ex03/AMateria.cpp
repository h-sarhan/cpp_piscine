/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:53:36 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 10:06:42 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	materiaType = "default";
}

AMateria::AMateria(const std::string &type)
{
	materiaType = type;
}

AMateria::AMateria(const AMateria &old)
{
	materiaType = old.materiaType;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	(void)rhs;
	return (*this);
}

AMateria::~AMateria(void)
{
}

const std::string &AMateria::getType() const
{
	return (materiaType);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
