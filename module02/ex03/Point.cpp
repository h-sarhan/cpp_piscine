/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:40:25 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/28 14:31:40 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
    // std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
    // std::cout << "Point float constructor called" << std::endl;
}

Point::Point(const Point &old) : x(old.x), y(old.y)
{
    // std::cout << "Point copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &old)
{
    (void)old;
    // std::cout << "Point dummy copy assignment constructor called" << std::endl;
    return (*this);
}

bool Point::operator==(const Point &rhs) const
{
    return (x == rhs.x && y == rhs.y);
}


Point::~Point(void)
{
    // std::cout << "Point destructor called" << std::endl;
}

const Fixed &Point::getX(void) const { return (x); }

const Fixed &Point::getY(void) const { return (y); }
