/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:26:16 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/13 11:27:30 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "Calling default Cure constructor" << std::endl;
}

Cure::Cure(const Cure &old): AMateria(old)
{
    std::cout << "Calling Cure copy constructor" << std::endl;
}

Cure &Cure::operator=(const Cure &rhs)
{
    std::cout << "Calling Cure copy assignment constructor" << std::endl;
	(void)rhs;
	return (*this);
}

Cure::~Cure(void)
{
    std::cout << "Calling Cure destructor" << std::endl;
}

AMateria *Cure::clone() const
{
	Cure *clone = new Cure();
	return (clone);
}

void Cure::use(ICharacter &target)
{
	(void)target;
}
