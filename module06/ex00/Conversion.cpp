/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:32:33 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/21 20:04:38 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

#include <iostream>

// Dummy default constructor
Conversion::Conversion(void) { _inputType = Conversion::INT; }

Conversion::Conversion(const std::string &str)
{
    _inputType = _getLiteralType(str);
    std::cout << "Literal Type: ";
    switch (_inputType)
    {
    case Conversion::CHAR_NORMAL:
        std::cout << "Normal char literal" << std::endl;
        break;
    case Conversion::CHAR_ESCAPE:
        std::cout << "Escape char literal" << std::endl;
        break;
    case Conversion::CHAR_HEXA:
        std::cout << "Hexadecimal char literal" << std::endl;
        break;
    case Conversion::CHAR_OCTAL:
        std::cout << "Octal char literal" << std::endl;
        break;
    case Conversion::INT:
        std::cout << "Int literal" << std::endl;
        break;
    case Conversion::FLOAT:
        std::cout << "Float literal" << std::endl;
        break;
    case Conversion::FLOAT_PSEUDO:
        std::cout << "Float pseudo literal" << std::endl;
        break;
    case Conversion::DOUBLE:
        std::cout << "Double literal" << std::endl;
        break;
    case Conversion::DOUBLE_PSEUDO:
        std::cout << "Double pseudo literal" << std::endl;
        break;
    default:
        throw std::invalid_argument("Invalid input");
        break;
    }
}

Conversion::Conversion(const Conversion &old) : _inputType(old._inputType) {}

Conversion &Conversion::operator=(const Conversion &rhs)
{
    if (this == &rhs)
    {
        return (*this);
    }
    _inputType = rhs._inputType;
    return (*this);
}

enum Conversion::LiteralType Conversion::_getLiteralType(const std::string &str)
{
    // Check if char literal by seeing if it is wrapped in quotes
    if (str[0] == '\'' && str[str.size() - 1] == '\'' && str.size() > 2)
    {
        return (_parseCharLiteral(str));
    }
    // Check if int literal by checking for the absence of '.' and 'f' and the if the
    // string is not equal to "nan"
    if (str.find('.') == std::string::npos && str.find('f') == std::string::npos &&
        str != "nan")
    {
        return (_parseIntLiteral(str));
    }
    // Check if float literal by checking if it is a pseudo literal or if it contains 'f'
    if (str == "-inff" || str == "+inff" || str == "nanf" ||
        (str.find("f") != std::string::npos))
    {
        return (_parseFloatLiteral(str));
    }
    if (str == "-inf" || str == "+inf" || str == "nan" ||
        (str.find(".") != std::string::npos))
    {
        return (_parseDoubleLiteral(str));
    }
    return (Conversion::ERROR);
}

enum Conversion::LiteralType Conversion::_parseDoubleLiteral(const std::string &str)
{
    if (str == "-inf" || str == "+inf" || str == "nan")
    {
        return (Conversion::DOUBLE_PSEUDO);
    }
    // Checking for invalid characters
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] != '+' && str[i] != '-' && std::isdigit(str[i]) == false && str[i] != '.')
        {
            return (Conversion::ERROR);
        }
    }
    // Checking if the string even contains numbers
    bool containsNumbers = false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str[i]) == true)
        {
            containsNumbers = true;
        }
    }
    if (containsNumbers == false)
    {
        return (Conversion::ERROR);
    }
    // Count dots, and signs
    size_t dotCount = 0;
    size_t signCount = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            dotCount++;
        }
        if (str[i] == '+' || str[i] == '-')
        {
            signCount++;
        }
    }
    if (dotCount > 1 || signCount > 1)
    {
        return (Conversion::ERROR);
    }
    // Check for + or - in the middle of the number
    for (size_t i = 1; i < str.size(); i++)
    {
        if (str[i] == '-' || str[i] == '+')
        {
            return (Conversion::ERROR);
        }
    }
    return (Conversion::DOUBLE);
}

enum Conversion::LiteralType Conversion::_parseFloatLiteral(const std::string &str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        return (Conversion::FLOAT_PSEUDO);
    }
    // Checking for invalid characters
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] != '+' && str[i] != '-' && std::isdigit(str[i]) == false &&
            str[i] != 'f' && str[i] != '.')
        {
            return (Conversion::ERROR);
        }
    }
    // Checking if the string even contains numbers
    bool containsNumbers = false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str[i]) == true)
        {
            containsNumbers = true;
        }
    }
    if (containsNumbers == false)
    {
        return (Conversion::ERROR);
    }
    // Count fs, dots, and signs
    size_t fCount = 0;
    size_t dotCount = 0;
    size_t signCount = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == 'f')
        {
            fCount++;
        }
        if (str[i] == '.')
        {
            dotCount++;
        }
        if (str[i] == '+' || str[i] == '-')
        {
            signCount++;
        }
    }
    if (dotCount > 1 || fCount != 1 || signCount > 1)
    {
        return (Conversion::ERROR);
    }
    // Check for + or - in the middle of the number
    for (size_t i = 1; i < str.size(); i++)
    {
        if (str[i] == '-' || str[i] == '+')
        {
            return (Conversion::ERROR);
        }
    }
    return (Conversion::FLOAT);
}

enum Conversion::LiteralType Conversion::_parseIntLiteral(const std::string &str)
{
    // Checking for invalid characters
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] != '+' && str[i] != '-' && std::isdigit(str[i]) == false)
        {
            return (Conversion::ERROR);
        }
    }
    // Checking if the string is simply just made up of - and +
    bool allSigns = true;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str[i]) == true)
        {
            allSigns = false;
            break;
        }
    }
    if (allSigns == true)
    {
        return (Conversion::ERROR);
    }
    // Checking for + and - in the middle of the number
    for (size_t i = 1; i < str.size(); i++)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            return (Conversion::ERROR);
        }
    }
    return (Conversion::INT);
}

enum Conversion::LiteralType Conversion::_parseCharLiteral(const std::string &str)
{
    const std::string escapeChars = "abfnrtv'\"?\\";
    const std::string inside = str.substr(1, str.size() - 2);
    // Normal character
    if (inside.size() == 1 && inside[0] != '\\')
    {
        return (Conversion::CHAR_NORMAL);
    }
    // Escape character
    else if (inside.size() == 2 && escapeChars.find(inside[1]) != std::string::npos)
    {
        return (Conversion::CHAR_ESCAPE);
    }
    else
    {
        const std::string rest = inside.substr(1, inside.size() - 1);
        // Checking for octal
        if (rest[0] != 'x' && rest.size() <= 3)
        {
            for (size_t i = 0; i < rest.size(); i++)
            {
                if (std::isdigit(rest[i]) == false)
                {
                    return (Conversion::ERROR);
                }
            }
            const size_t octalVal = std::strtoul(rest.c_str(), NULL, 8);
            if (octalVal > 255)
            {
                return (Conversion::ERROR);
            }
            return (Conversion::CHAR_OCTAL);
        }
        // Checking for Hexa
        if (rest[0] == 'x' && rest.size() <= 3)
        {
            for (size_t i = 1; i < rest.size(); i++)
            {
                if (std::isdigit(rest[i]) == false &&
                    std::string("abcdef").find(std::tolower(rest[i])) ==
                        std::string::npos)
                {
                    return (Conversion::ERROR);
                }
            }
            const size_t hexVal =
                std::strtoul(rest.substr(1, rest.size() - 1).c_str(), NULL, 16);
            if (hexVal > 255)
            {
                return (Conversion::ERROR);
            }
            return (Conversion::CHAR_HEXA);
        }
        return (Conversion::ERROR);
    }
}

char Conversion::getChar(void)
{
    switch (_inputType)
    {
    case Conversion::CHAR_NORMAL:
        
        break;
    
    default:
        break;
    }
}

int Conversion::getInt(void) { return (0); }

float Conversion::getFloat(void) { return (0.0f); }

double Conversion::getDouble(void) { return (0.0); }

// Dummy destructor
Conversion::~Conversion(void) {}