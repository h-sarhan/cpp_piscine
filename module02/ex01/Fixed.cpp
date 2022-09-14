/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:41:53 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/14 12:40:36 by hsarhan          ###   ########.fr       */
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

// // ! Try comparing the difference at every iteration of the while loop
// Fixed::Fixed(const float num)
// {
// 	std::cout << "Float constructor called" << std::endl;
// 	const int intPart = static_cast<int>(num);
// 	const float fracPart = (num - intPart);
// 	// std::cout << fracPart << std::endl;
// 	_rawBits = intPart;
// 	_rawBits <<= 8;
// 	float sum = 0.0f;
// 	float distance = fracPart;
// 	float divisor;
// 	for (int i = 1; i < _fracBits + 1; i++)
// 	{
// 		divisor = 1.0f / pow(2, i);
// 		if (abs(fracPart - (sum + divisor)) < distance)
// 		{
// 			_rawBits |= pow(2, 8 - i);
// 			sum += divisor;
// 			distance = abs(fracPart - sum);
// 		}
		
// 	}
// }

// * Old mostly working algorithm
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	const int intPart = static_cast<int>(num);
	 float fracPart = (num - intPart);
	// std::cout << fracPart << std::endl;
	_rawBits = intPart;
	_rawBits <<= 8;
	// float sum = 0.0f;
	// float d
	float divisor;
	for (int i = 1; i < _fracBits + 1; i++)
	{
		divisor = 1.0f / pow(2, i);
		if (divisor < fracPart)
		{
			_rawBits |= pow(2, 8 - i);
			fracPart -= divisor;
		}
	}
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
	// ! Use roundf here on toFloat return value
	return (roundf(toFloat()));
}

float Fixed::toFloat(void) const
{
	float	intPart = _rawBits >> 8;
	// std::cout << "\nRAW BITS: " << _rawBits << std::endl;
	int		fractPart = _rawBits & 0xFF;
	// std::cout << fractPart << std::endl;
	if (fractPart == 0)
	{
		return (intPart);
	}
	float	decimal = 0.0f;
	for (int i = 1; i < _fracBits + 1; i++)
	{
		if (((fractPart >> (8 - i)) & 1) == 1)
		{
			// std::cout << "Adding " << 1.0f / pow(2, i) << " to " << decimal << std::endl;
			decimal += 1.0f / pow(2, i);
		}
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

std::ostream &operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}


const int Fixed::_fracBits = 8;
