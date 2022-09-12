/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:41:53 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/12 12:13:01 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const Fixed &old)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = old;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = num;
	_rawBits <<= 8;
}

// ! HARD
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	(void)num;
}

Fixed &Fixed::operator=(const Fixed &old)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&old == this)
		return (*this);
	_rawBits = old.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

int Fixed::toInt(void) const
{
	return (_rawBits >> 8);
}

const int Fixed::_fracBits = 8;
