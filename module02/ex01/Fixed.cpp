/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:41:53 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 08:37:08 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
    _neg = false;
}

Fixed::Fixed(const Fixed &old)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = old._rawBits;
    this->_neg = old._neg;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    if (num < 0)
    {
        _neg = true;
        _rawBits = -num;
        _rawBits <<= _fracBits;
    }
    else
    {
        _neg = false;
        _rawBits = num;
        _rawBits <<= _fracBits;
    }
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    int intPart;
    float fracPart;
    if (num < 0)
    {
        _neg = true;
        intPart = static_cast<int>(-num);
        fracPart = (-num - intPart);
    }
    else
    {
        _neg = false;
        intPart = static_cast<int>(num);
        fracPart = (num - intPart);
    }
    _rawBits = intPart;
    _rawBits <<= _fracBits;
    float divisor;
    for (int i = 1; i < _fracBits + 1; i++)
    {
        divisor = 1.0f / pow(2, i);
        if (divisor < fracPart)
        {
            _rawBits |= pow(2, _fracBits - i);
            fracPart -= divisor;
        }
    }
    const float epsilon = 1.0f / pow(2, _fracBits);
    const float current = abs(toFloat());
    const float target = abs(num);
    if (abs((current + epsilon) - target) < abs(current - target))
    {
        _rawBits++;
    }
}

Fixed &Fixed::operator=(const Fixed &old)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (&old == this)
        return (*this);
    _rawBits = old.getRawBits();
    _neg = old._neg;
    return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

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

int Fixed::toInt(void) const { return (toFloat()); }

float Fixed::toFloat(void) const
{
    float intPart = _rawBits >> _fracBits;
    int fractPart = _rawBits & (pow(2, _fracBits) - 1);
    if (fractPart == 0)
    {
        if (_neg == true)
        {
            return (-intPart);
        }
        return (intPart);
    }
    float decimal = 0.0f;
    for (int i = 1; i < _fracBits + 1; i++)
    {
        if (((fractPart >> (_fracBits - i)) & 1) == 1)
        {
            decimal += 1.0f / pow(2, i);
        }
    }
    if (_neg == true)
    {
        return (intPart + decimal) * -1;
    }
    return (intPart + decimal);
}

unsigned int Fixed::pow(unsigned int num, unsigned int pow)
{
    unsigned int res = 1;
    for (unsigned int i = 0; i < pow; i++)
    {
        res *= num;
    }
    return (res);
}

float Fixed::abs(float num)
{
    if (num < 0.0f)
        return (-num);
    return (num);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

const int Fixed::_fracBits = 8;
