/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:16:02 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:42:41 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie stackZomb("stack");
	
	stackZomb.announce();

	randomChump("Random stack zombie");
	
	Zombie *heapZomb = newZombie("heap");
	heapZomb->announce();

	delete heapZomb;
	return (0);
}