/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:06:48 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/28 14:53:35 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	std::cout << 
	" _____  \n" <<
	" |    / \n" <<
	" | * / \n" <<
	" |  / \n" <<
	" | / \n" <<
	" |/ \n"
	 << std::endl; 

	if (bsp(Point(0, 0), Point(0, 10), Point(5, 10), Point(1, 3)))
	{
		std::cout << std::endl;
		std::cout << "Point is in triangle" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Point is not in triangle" << std::endl;
	}

	std::cout << 
	" _____  \n" <<
	" |    / \n" <<
	" *   / \n" <<
	" |  / \n" <<
	" | / \n" <<
	" |/ \n"
	 << std::endl; 

	if (bsp(Point(0, 0), Point(0, 10), Point(5, 10), Point(0, 3)))
	{
		std::cout << std::endl;
		std::cout << "Point is in triangle" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Point is not in triangle" << std::endl;
	}

	std::cout << 
	"   _____  \n" <<
	"   |    / \n" <<
	" * |   / \n" <<
	"   |  / \n" <<
	"   | / \n" <<
	"   |/ \n"
	 << std::endl; 

	if (bsp(Point(0, 0), Point(0, 10), Point(5, 10), Point(-1, 3)))
	{
		std::cout << std::endl;
		std::cout << "Point is in triangle" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Point is not in triangle" << std::endl;
	}

	std::cout << 
	"   __.__  \n" <<
	"   |    / \n" <<
	"   |   / \n" <<
	"   |  / \n" <<
	"   | / \n" <<
	"   |/ \n"
	 << std::endl; 

	if (bsp(Point(0, 0), Point(0, 10), Point(5, 10), Point(1, 10)))
	{
		std::cout << std::endl;
		std::cout << "Point is in triangle" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Point is not in triangle" << std::endl;
	}

	std::cout << 
	"   .____  \n" <<
	"   |    / \n" <<
	"   |   / \n" <<
	"   |  / \n" <<
	"   | / \n" <<
	"   |/ \n"
	 << std::endl; 

	if (bsp(Point(0, 0), Point(0, 10), Point(5, 10), Point(0, 10)))
	{
		std::cout << std::endl;
		std::cout << "Point is in triangle" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Point is not in triangle" << std::endl;
	}

	std::cout << 
	"    _____  \n" <<
	"   |*   / \n" <<
	"   |   / \n" <<
	"   |  / \n" <<
	"   | / \n" <<
	"   |/ \n"
	 << std::endl; 

	if (bsp(Point(0, 0), Point(0, 10), Point(5, 10), Point(1, 9)))
	{
		std::cout << std::endl;
		std::cout << "Point is in triangle" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Point is not in triangle" << std::endl;
	}
}