/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:36:18 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 09:12:47 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
#define FIXED

#include <cmath>
#include <iostream>

class Fixed
{
public:
    Fixed(void);
    Fixed(const Fixed &old);
    Fixed(const int num);
    Fixed(const float num);
    Fixed &operator=(const Fixed &old);
    ~Fixed(void);

    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    bool operator<(const Fixed &rhs) const;
    bool operator>(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    Fixed &operator++();
    Fixed operator++(int);

    Fixed &operator--();
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(const int raw);
    int toInt(void) const;
    float toFloat(void) const;

    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

private:
    int _rawBits;
    bool _neg;
    static const int _fracBits;
    static unsigned int pow(unsigned int num, unsigned int pow);
    static float abs(float num);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif