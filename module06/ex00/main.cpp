/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:45:43 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 14:55:33 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>



int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Please input a signle argument" << std::endl;
        return (1);
    }
    Conversion conversion = Conversion(argv[1]);

    std::cout << "char: " << charConv << std::endl;
    std::cout << "int: " << intConv << std::endl;
    std::cout << "float: " << floatConv << std::endl;
    std::cout << "double: " << doubleConv << std::endl;
}
