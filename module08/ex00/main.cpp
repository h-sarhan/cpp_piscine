/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:19:52 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/17 15:13:08 by hsarhan          ###   ########.fr       */
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
	std::vector<int>::iterator res = easyfind(numVec, 12);
	std::cout << *res << std::endl;
	res++;
	std::cout << *res << std::endl;
}