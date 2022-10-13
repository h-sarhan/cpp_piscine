/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:36:53 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/13 11:27:33 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Calling default Ice constructor" << std::endl;
}

Ice::Ice(const Ice &old) :AMateria(old)
{
    std::cout << "Calling Ice copy constructor" << std::endl;
}

Ice &Ice::operator=(const Ice &rhs)
{
    std::cout << "Calling Ice copy assignment constructor" << std::endl;
	(void)rhs;
	return (*this);
}

Ice::~Ice(void)
{
    std::cout << "Calling Ice destructor" << std::endl;
}

AMateria *Ice::clone() const
{
	Ice *clone = new Ice();
	return (clone);
}

void Ice::use(ICharacter &target)
{
	(void)target;
}
