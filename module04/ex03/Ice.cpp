/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:36:53 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 10:06:10 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(const Ice &old) :AMateria(old)
{
}

Ice &Ice::operator=(const Ice &rhs)
{
	(void)rhs;
	return (*this);
}

Ice::~Ice(void)
{
}

AMateria *Ice::clone() const
{
	Ice *clone = new Ice();
	return (clone);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
