/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:34:10 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 06:44:32 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// ! Add tests
int main()
{
	DiamondTrap diamond("Bob");
	diamond.attack("Fernando");
	diamond.highFivesGuys();
	diamond.whoAmI();
	diamond.printStats();
};