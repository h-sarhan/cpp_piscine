/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:34:10 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/28 15:35:55 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap ted("ted");
	ScavTrap tod("tod");
	ted.attack("tod");
	ted.attack("tod");
	ted.attack("tod");
	tod.beRepaired(10);
	tod.beRepaired(10);
	tod.attack("ted");
	tod.guardGate();
}
