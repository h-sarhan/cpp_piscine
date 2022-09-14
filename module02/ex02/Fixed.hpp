/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:36:18 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/14 20:10:21 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
#define FIXED

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &old);
	Fixed(const int num);
	Fixed(const float num);
	Fixed &operator=(const Fixed &old);
	~Fixed(void);

	Fixed operator+(const Fixed& rhs) const;
	Fixed operator-(const Fixed& rhs) const;
	Fixed operator*(const Fixed& rhs) const;
	Fixed operator/(const Fixed& rhs) const;
	
	bool operator<(const Fixed& rhs) const;
	bool operator>(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;

	Fixed& operator++();
	Fixed operator++(int);

	Fixed& operator--();
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(const int raw);
	int toInt(void) const;
	float toFloat(void) const;

private:
	int _rawBits;
	bool neg;
	static const int _fracBits;
	static unsigned int pow(unsigned int num, unsigned int pow);
	static float abs(float num);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif