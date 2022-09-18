/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:06:48 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 09:10:13 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// ! Add more tests
int main(void)
{
    Fixed a(0.0f);
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "max of " << a << " and " << b << " is " << Fixed::max(a, b) << std::endl;
    std::cout << "min of " << a << " and " << b << " is " << Fixed::min(a, b) << std::endl;
	std::cout << a / b << std::endl;
	std::cout << a / Fixed(0) << std::endl;
	std::cout << a * b << std::endl;
	std::cout << Fixed(2) * b << std::endl;
	std::cout << (Fixed(2) == Fixed(2)) << std::endl;
	std::cout << (Fixed(2) == Fixed(3)) << std::endl;
	std::cout << (Fixed(2) < Fixed(3)) << std::endl;
	std::cout << (Fixed(2) > Fixed(3)) << std::endl;
	std::cout << (Fixed(3) >= Fixed(3)) << std::endl;
	std::cout << (Fixed(3) <= Fixed(3)) << std::endl;
    return 0;
}