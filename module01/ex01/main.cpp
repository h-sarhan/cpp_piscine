/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:16:02 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/09 07:56:42 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	size_t numZombies;

	numZombies = 10;
	std::cout << "Creating zombies" << std::endl;
	Zombie zomb = Zombie("Main");
	Zombie *horde = zomb.zombieHorde(numZombies, "Horde");
	std::cout << std::endl;
	
	std::cout << "Announcing zombies" << std::endl;
	for (size_t i = 0; i < numZombies; i++)
	{
		horde[i].announce();
	}

	std::cout << "Deleting zombies" << std::endl;
	delete[] horde;
	std::cout << std::endl;
}