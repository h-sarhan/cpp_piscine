/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:53:36 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/13 10:55:27 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "Calling default AMateria constructor" << std::endl;
	materiaType = "default";
}

AMateria::AMateria(const std::string &type)
{
	std::cout << "Calling AMateria constructor" << std::endl;
	materiaType = type;
}

AMateria::AMateria(const AMateria &old)
{
	std::cout << "Calling AMateria copy constructor" << std::endl;
	materiaType = old.materiaType;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	(void)rhs;
	std::cout << "Calling AMateria copy assignment constructor" << std::endl;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "Calling AMateria destructor" << std::endl;
}

const std::string &AMateria::getType() const
{
	return (materiaType);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
