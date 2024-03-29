/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:58:24 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/23 14:21:45 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION
#define CONVERSION

#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

class Conversion
{
public:
    enum LiteralType
    {
        CHAR_NORMAL,
        CHAR_ESCAPE,
        CHAR_HEXA,
        CHAR_OCTAL,
        INT,
        FLOAT,
        FLOAT_PSEUDO,
        DOUBLE,
        DOUBLE_PSEUDO,
        ERROR,
    };
    Conversion(void);
    Conversion(const std::string &str);
    Conversion(const Conversion &old);
    Conversion &operator=(const Conversion &rhs);
    ~Conversion(void);

    class NonDisplayableCharacterException : public std::exception
    {
        const char *what() const throw();
    };

    class ImpossibleConversionException : public std::exception
    {
        const char *what() const throw();
    };

    char getChar(void);
    int getInt(void);
    float getFloat(void);
    double getDouble(void);

private:
    enum LiteralType _getLiteralType(const std::string &str);
    enum LiteralType _parseCharLiteral(const std::string &str);
    enum LiteralType _parseIntLiteral(const std::string &str);
    enum LiteralType _parseFloatLiteral(const std::string &str);
    enum LiteralType _parseDoubleLiteral(const std::string &str);
    enum LiteralType _inputType;
    bool _isDigit(const char ch);
    std::string _rawString;
};

#endif