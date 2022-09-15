/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:32:13 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 08:02:40 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
	: type("Base animal")
{
	std::cout << "Calling default WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &old)
	: type(old.type)
{
	std::cout << "Calling WrongAnimal copy constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "Calling WrongAnimal copy assignment constructor" << std::endl;
	if (&rhs == this)
		return (*this);
	type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Calling WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "..." << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
	return (type);
}
