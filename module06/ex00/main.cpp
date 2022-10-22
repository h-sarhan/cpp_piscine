/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:45:43 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/22 14:06:41 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <iostream>


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Please input a signle argument" << std::endl;
        return (1);
    }
    try
    {
        Conversion conversion = Conversion(argv[1]);
        try
        {
            const char charConv = conversion.getChar();
            std::cout << "char: " << charConv << std::endl;
        }
        catch(const Conversion::ImpossibleConversionException& e)
        {
            std::cout << "char: impossible" << std::endl;
        }
        catch(const Conversion::NonDisplayableCharacterException& e)
        {
            std::cout << "char: Non displayable" << std::endl;
        }

        std::cout << "int: " <<  conversion.getInt() << std::endl;
        std::cout << "float: " << conversion.getFloat() << std::endl;
        std::cout << "double: " << conversion.getDouble() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
