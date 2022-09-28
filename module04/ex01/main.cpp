/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:51:24 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/28 16:54:15 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Dog* chris = new Dog();
	const Cat* jinx = new Cat();

	jinx->makeSound();
	chris->makeSound();
	chris->printThoughts();
	const Dog chris2 = *chris;
	delete chris;
	Dog chris3 = chris2;
	chris2.printThoughts();
	chris3.printThoughts();
	jinx->printThoughts();
	delete jinx;
	return 0;
}