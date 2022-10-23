/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:34:22 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/23 14:40:13 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

#include <iostream>

int	main(void)
{
	Data *wow = new Data();
	wow->a = 1;
	wow->b = 2;
	wow->c = 3;
	uintptr_t wowSerialized = serialize(wow);
	Data *wowDeserialized = deserialize(wowSerialized);
	if (wowDeserialized == wow)
	{
		std::cout << "Pointers are equivalent" << std::endl;
	}
	std::cout << "a is " << wowDeserialized->a << std::endl;
	std::cout << "b is " << wowDeserialized->b << std::endl;
	std::cout << "c is " << wowDeserialized->c << std::endl;
	delete wowDeserialized;
}