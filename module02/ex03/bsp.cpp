/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 09:34:14 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/28 14:53:47 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool isInFront(Point p1, Point p2, Point p3)
{
    return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
            (p2.getX() - p3.getX()) * (p1.getY() - p3.getY())) > 0;
}

static bool isPointOnLine(const Point& point, const Point& a, const Point& b)
{
    return	((point.getX() - b.getX()) * (a.getY() - b.getY()) -
            (a.getX() - b.getX()) * (point.getY() - b.getY()) == 0);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	if (point == a || point == b || point == c)
        return (false);

    if (isPointOnLine(point, a, b) || isPointOnLine(point, b, c) || isPointOnLine(point, a, c))
        return (false);

    bool inFrontAB = isInFront(point, a, b);
    bool inFrontBC = isInFront(point, b, c);
    bool inFrontCA = isInFront(point, c, a);

    bool behind = !inFrontAB || !inFrontBC || !inFrontCA;
    bool inFront = inFrontAB || inFrontBC || inFrontCA;


    return !(behind && inFront);
}
