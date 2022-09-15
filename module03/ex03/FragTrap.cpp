/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 03:55:40 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 05:46:48 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	: ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hp = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::FragTrap(const FragTrap &old)
	: ClapTrap(old)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	_hp = old._hp;
	_energy = old._energy;
	_damage = old._damage;
	_name = old._name;
}

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	_hp = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap copy assignment constructor called" << std::endl;
	if (&rhs == this)
		return (*this);

	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Fragtrap " << _name << " has successfully high fived multiple guys!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_energy > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _damage << " points of damage!" << std::endl;
		_energy--;
	}
}
