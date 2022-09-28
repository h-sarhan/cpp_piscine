/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:34:10 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/28 15:16:33 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1;
	ClapTrap clap2("clapper");
	ClapTrap clap3(clap2);
	ClapTrap clap4 = clap3;
	
	clap1.attack("clapper");
	clap1.attack("clapper");
	clap1.attack("clapper");
	clap1.attack("clapper");
	clap1.attack("clapper");
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(0);
	clap2.takeDamage(0);

	clap2.beRepaired(0);
	clap2.beRepaired(0);
	clap2.beRepaired(0);
	clap2.beRepaired(0);
	clap2.beRepaired(0);
	clap2.beRepaired(0);
}