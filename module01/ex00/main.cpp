/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:16:02 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/09 02:24:31 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	// Creating zombies;
	Zombie stackZombie = Zombie("Stack");

	// Creating heap zombie
	Zombie *heapZombie = stackZombie.newZombie("Heap");

	std::cout << "Announcing zombies" << std::endl;
	stackZombie.announce();
	heapZombie->announce();
	std::cout << std::endl;
	
	std::cout << "Creating random zombies" << std::endl;
	stackZombie.randomChump("Random stack zombie");
	heapZombie->randomChump("Random heap zombie");
	std::cout << std::endl;
	
	std::cout << "Deleting heap zombie" << std::endl;
	delete heapZombie;
	std::cout << std::endl;
}