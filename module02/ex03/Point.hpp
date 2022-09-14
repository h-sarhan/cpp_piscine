/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:33:48 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/14 21:53:39 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT
#define POINT

#include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &old);
	Point &operator=(const Point &old);
	~Point(void);
private:
	const Fixed x;
	const Fixed y;
};

bool bsp(const Point a, const Point b, const Point c, const Point point);
#endif