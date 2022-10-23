/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:45:43 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/23 14:20:07 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

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
        catch (const Conversion::ImpossibleConversionException &e)
        {
            std::cout << "char: impossible" << std::endl;
        }
        catch (const Conversion::NonDisplayableCharacterException &e)
        {
            std::cout << "char: Non displayable" << std::endl;
        }
        try
        {
            const int intConv = conversion.getInt();
            std::cout << "int: " << intConv << std::endl;
        }
        catch (const Conversion::ImpossibleConversionException &e)
        {
            std::cout << "int: impossible" << std::endl;
        }
        try
        {
            const float floatConv = conversion.getFloat();
            if (floatConv != floatConv)
            {
                std::cout << "float: nanf" << std::endl;
            }
            else if (floatConv == std::numeric_limits<float>::infinity())
            {
                std::cout << "float: +inff" << std::endl;
            }
            else if (floatConv == -std::numeric_limits<float>::infinity())
            {
                std::cout << "float: -inff" << std::endl;
            }
            else
            {
                std::cout << "float: " << floatConv << std::endl;
            }
        }
        catch (const Conversion::ImpossibleConversionException &e)
        {
            std::cout << "float: impossible" << std::endl;
        }
        try
        {
            const double doubleConv = conversion.getDouble();
            if (doubleConv != doubleConv)
            {
                std::cout << "double: nan" << std::endl;
            }
            else if (doubleConv == std::numeric_limits<double>::infinity())
            {
                std::cout << "double: +inf" << std::endl;
            }
            else if (doubleConv == -std::numeric_limits<double>::infinity())
            {
                std::cout << "double: -inf" << std::endl;
            }
            else
            {
                std::cout << "double: " << doubleConv << std::endl;
            }
        }
        catch (const Conversion::ImpossibleConversionException &e)
        {
            std::cout << "double: impossible" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
