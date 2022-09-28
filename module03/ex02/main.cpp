/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:34:10 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/28 15:41:23 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap ted("ted");
	FragTrap tod("tod");
	ted.attack("tod");
	ted.attack("tod");
	ted.attack("tod");
	tod.beRepaired(20);
	tod.beRepaired(20);
	tod.attack("ted");
	tod.highFivesGuys();
}
