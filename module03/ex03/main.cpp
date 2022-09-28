/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:34:10 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/28 15:47:37 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("Bob");
	diamond.attack("Fernando");
	diamond.highFivesGuys();
	diamond.whoAmI();
	diamond.printStats();
	diamond.beRepaired(1);
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.takeDamage(1);
};