/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:32:13 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 08:06:39 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "Calling default WrongCat constructor" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &old)
	: WrongAnimal(old)
{
	std::cout << "Calling WrongCat copy constructor" << std::endl;
	type = old.type;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "Calling WrongCat copy assignment constructor" << std::endl;
	if (&rhs == this)
		return (*this);
	type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "Calling WrongCat destructor" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow 😻" << std::endl;
}
