/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 04:39:08 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 06:54:33 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP
# define DIAMOND_TRAP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :  public FragTrap, public ScavTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap &old);
	DiamondTrap &operator=(const DiamondTrap &rhs);
	~DiamondTrap(void);
	using ScavTrap::attack;
	void whoAmI(void);
	void printStats();
private:
	using ScavTrap::_energy;
	std::string _name;
};

#endif
