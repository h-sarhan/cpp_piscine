/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:32:13 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 07:55:59 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
	: type("Base animal")
{
	std::cout << "Calling default Animal constructor" << std::endl;
}

Animal::Animal(const Animal &old)
	: type(old.type)
{
	std::cout << "Calling Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "Calling Animal copy assignment constructor" << std::endl;
	if (&rhs == this)
		return (*this);
	type = rhs.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Calling Animal destructor" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "..." << std::endl;
}

const std::string& Animal::getType(void) const
{
	return (type);
}
