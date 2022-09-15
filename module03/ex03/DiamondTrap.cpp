/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 04:41:25 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 06:53:56 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	: _name("default")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::_name = _name + "clap_name";
	ClapTrap::_hp = FragTrap::_hp;
	ClapTrap::_energy = ScavTrap::_energy;
	ClapTrap::_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const std::string &name)
	: _name(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	ClapTrap::_name = _name + "_clap_name";
	ClapTrap::_hp = FragTrap::_hp;
	ClapTrap::_energy = ScavTrap::_energy;
	ClapTrap::_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &old)
	: ClapTrap(old), FragTrap(old), ScavTrap(old)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	_name = old._name;
	ClapTrap::_name = old.ClapTrap::_name;
	_hp = old._hp;
	_energy = old._energy;
	_damage = old._damage;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "DiamondTrap copy assignment constructor called" << std::endl;
	if (&rhs == this)
		return (*this);
	_name = rhs._name;
	ClapTrap::_name = rhs.ClapTrap::_name;
	_hp = rhs._hp;
	_energy = rhs._energy;
	_damage = rhs._damage;
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My real name is " << _name << std::endl;
	std::cout << "My claptrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::printStats()
{
	std::cout << "HP is: "<< _hp <<std::endl;
	std::cout << "Energy points is: "<< _energy <<std::endl;
	std::cout << "Damage is: "<< _damage <<std::endl;
}