/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 03:55:40 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/28 15:38:14 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	: ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hp = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &old)
	: ClapTrap(old)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_hp = old._hp;
	_energy = old._energy;
	_damage = old._damage;
	_name = old._name;
}

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	_hp = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap copy assignment constructor called" << std::endl;
	if (&rhs == this)
		return (*this);
	this->_damage = rhs._damage;
	this->_energy = rhs._energy;
	this->_hp = rhs._hp;
	this->_name = rhs._name;
	return (*this);
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap" << _name << " is now in gatekeeper mode" << std::endl;
}
