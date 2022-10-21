/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:58:24 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/21 20:14:08 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION
#define CONVERSION

#include <string>
#include <stdexcept>
#include <cctype>
#include <cstdlib>

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

    std::string getChar(void);
    std::string getInt(void);
    std::string getFloat(void);
    std::string getDouble(void);

private:
	enum LiteralType _getLiteralType(const std::string &str);
	enum LiteralType _parseCharLiteral(const std::string &str);
	enum LiteralType _parseIntLiteral(const std::string &str);
	enum LiteralType _parseFloatLiteral(const std::string &str);
	enum LiteralType _parseDoubleLiteral(const std::string &str);
	enum LiteralType _inputType;
	std::string _rawString;
};

#endif