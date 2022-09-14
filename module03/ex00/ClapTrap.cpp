/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:08:20 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/14 23:21:53 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _hp(10), _energy(10), _damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &old)
	: _name(old._name), _hp(old._hp), _energy(old._energy), _damage(old._damage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	if (&rhs == this)
		return (*this);
	*this = ClapTrap(rhs);
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energy > 0)
	{
		std::cout << "ClapTrap " << _name <<  " attacks " <<  target << " causing " << _damage << " points of damage!" << std::endl;
		_energy--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp >= amount)
	{
		std::cout << "ClapTrap has taken " << amount <<  " points of damage!" << std::endl;
		_hp -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0)
	{
		std::cout << "ClapTrap has repaired itself for " << amount <<  " hp!" << std::endl;
		_hp += amount;
		_energy--;
	}
}

