/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:32:13 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/28 16:52:55 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
: brain(new Brain)
{
	std::cout << "Calling default Cat constructor" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &old)
	: Animal(old)
{
	std::cout << "Calling Cat copy constructor" << std::endl;
	brain = new Brain(*old.brain);
	type = old.type;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Calling Cat copy assignment constructor" << std::endl;
	if (&rhs == this)
		return (*this);
	brain = new Brain(*rhs.brain);
	type = rhs.type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Calling Cat destructor" << std::endl;
	delete brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow 😻" << std::endl;
}

void Cat::printThoughts(void) const
{
	brain->printFiveThoughts();
}
