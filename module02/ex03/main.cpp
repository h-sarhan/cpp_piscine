/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:06:48 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/14 20:12:48 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// ! Add more tests
int main(void)
{
	Fixed a(0.0f);
	// Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}