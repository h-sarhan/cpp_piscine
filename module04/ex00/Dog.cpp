/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:32:13 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 08:00:34 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Calling default Dog constructor" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &old)
	: Animal(old)
{
	std::cout << "Calling Dog copy constructor" << std::endl;
	type = old.type;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Calling Dog copy assignment constructor" << std::endl;
	if (&rhs == this)
		return (*this);
	type = rhs.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Calling Dog destructor" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Bork 🐶" << std::endl;
}
