/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:32:27 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/17 11:40:47 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	addOneAndPrint(int num)
{
	std::cout << "Num + 1 is " << num + 1 << std::endl;
}

void	printFirstChar(std::string str)
{
	std::cout << "First char is " << str.substr(0, 1) << std::endl;
}

int	main(void)
{
	int nums[] = {0, 1, 2, 3, 4, 5};
	iter(nums, 6, addOneAndPrint);
	std::string	strs[] = {"Oh", "hi", "Mark!", "How", "is", "your", "day!"};
	iter(strs, 7, printFirstChar);
}
