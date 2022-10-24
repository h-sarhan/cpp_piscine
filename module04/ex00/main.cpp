/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:51:24 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/24 12:20:06 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// Commented out lines will fail to compile
int main()
{
	const Dog	*dog = new Dog();
	const Cat	*cat = new Cat();
	cat->makeSound();
	dog->makeSound();

	const Animal *jinx = new Cat();
	jinx->makeSound();

	const WrongAnimal *meta = new WrongAnimal();
	// const WrongAnimal *j = new Dog();
	const WrongAnimal *i = new WrongCat();

	// std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	// j->makeSound();
	meta->makeSound();
	delete dog;
	delete cat;
	delete meta;
	delete i;
	delete jinx;
	return 0;
}