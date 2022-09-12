/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:41:53 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/12 11:49:12 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_rawBits = 0;
}

Fixed::Fixed(const Fixed &old)
{
	_rawBits = old._rawBits;
}

Fixed &Fixed::operator=(const Fixed &old)
{
	if (&old == this)
		return (*this);
	_rawBits = old._rawBits;
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void Fixed::setRawBits(const int raw)
{
	_rawBits = raw;
}

const int Fixed::_fracBits = 8;
