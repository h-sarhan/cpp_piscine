/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:19:52 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/19 21:57:55 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <list>
#include <iostream>

int	main(void)
{
	std::vector<int> numVec(10, 42);
	numVec[1] = 12;
	numVec[2] = 54;
	try
	{
		std::vector<int>::iterator res = easyfind(numVec, 12);
		std::cout << *res << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
