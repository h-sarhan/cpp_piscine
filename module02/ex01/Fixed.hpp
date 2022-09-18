/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:36:18 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 08:37:20 by hsarhan          ###   ########.fr       */
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

    int getRawBits(void) const;
    void setRawBits(const int raw);
    int toInt(void) const;
    float toFloat(void) const;

private:
    int _rawBits;
    bool _neg;
    static const int _fracBits;
    static unsigned int pow(unsigned int num, unsigned int pow);
    static float abs(float num);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif