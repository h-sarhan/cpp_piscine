/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:40:25 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/14 21:54:12 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
	: x(0), y(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y)
	: x(x), y(y)
{
	std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Point &old)
	: x(old.x), y(old.y)
{
	std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point &old)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	if (&old == this)
		return (*this);
	*this = Point(old);
	return (*this); 
}

Point::~Point(void)
{
	std::cout << "Destructor constructor called" << std::endl;
}
