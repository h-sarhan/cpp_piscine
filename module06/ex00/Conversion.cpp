/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:32:33 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/27 20:08:45 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

// Dummy default constructor
Conversion::Conversion(void) : _inputType(Conversion::INT), _rawString("") {}

Conversion::Conversion(const std::string &str) : _rawString(str)
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

Conversion::Conversion(const Conversion &old)
    : _inputType(old._inputType), _rawString(old._rawString)
{
}

Conversion &Conversion::operator=(const Conversion &rhs)
{
    if (this == &rhs)
    {
        return (*this);
    }
    _inputType = rhs._inputType;
    _rawString = rhs._rawString;
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
        (str.find("f") != std::string::npos && str != "-inf" && str != "+inf" &&
         str != "nan"))
    {
        return (_parseFloatLiteral(str));
    }
    // Check if double literal
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
        if (str[i] != '+' && str[i] != '-' && _isDigit(str[i]) == false && str[i] != '.')
        {
            return (Conversion::ERROR);
        }
    }
    // Checking if the string even contains numbers
    bool containsNumbers = false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (_isDigit(str[i]) == true)
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
        if (str[i] != '+' && str[i] != '-' && _isDigit(str[i]) == false &&
            str[i] != 'f' && str[i] != '.')
        {
            return (Conversion::ERROR);
        }
    }
    // Checking if the string even contains numbers
    bool containsNumbers = false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (_isDigit(str[i]) == true)
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
    // Check that the last character is f
    if (str[str.size() - 1] != 'f')
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
        if (str[i] != '+' && str[i] != '-' && _isDigit(str[i]) == false)
        {
            return (Conversion::ERROR);
        }
    }
    // Checking if the string is simply just made up of - and +
    bool allSigns = true;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (_isDigit(str[i]) == true)
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
        if (rest.length() == 0 || (rest.length() == 1 && rest[0] == 'x'))
        {
            return (Conversion::ERROR);
        }
        // Checking for octal
        if (rest[0] != 'x' && rest.size() <= 3)
        {
            for (size_t i = 0; i < rest.size(); i++)
            {
                if (_isDigit(rest[i]) == false || rest[i] == '8' || rest[i] == '9')
                {
                    return (Conversion::ERROR);
                }
            }
            size_t octalVal;
            std::stringstream(rest) >> std::oct >> octalVal;
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
                if (_isDigit(rest[i]) == false && std::string("abcdef").find(std::tolower(
                                                      rest[i])) == std::string::npos)
                {
                    return (Conversion::ERROR);
                }
            }
            size_t hexVal;
            std::stringstream(rest) >> std::hex >> hexVal;
            if (hexVal > 255)
            {
                return (Conversion::ERROR);
            }
            return (Conversion::CHAR_HEXA);
        }
        return (Conversion::ERROR);
    }
}

const char *Conversion::ImpossibleConversionException::what() const throw()
{
    return ("Impossible conversion");
}

const char *Conversion::NonDisplayableCharacterException::what() const throw()
{
    return ("Non displayable character");
}

char Conversion::getChar(void)
{
    switch (_inputType)
    {
    // Example 'd'
    case Conversion::CHAR_NORMAL:
    {
        if (_rawString[1] >= 32 && _rawString[1] <= 126)
        {
            return (_rawString[1]);
        }
        throw NonDisplayableCharacterException();
    }
    // Example '\n'
    case Conversion::CHAR_ESCAPE:
    {
        switch (_rawString[2])
        {
        case 'a':
        case 'b':
        case 'f':
        case 'n':
        case 'r':
        case 't':
        case 'v':
            throw NonDisplayableCharacterException();
        case '\'':
            return ('\'');
        case '\\':
            return ('\\');
        case '\"':
            return ('\"');
        case '?':
            return ('\?');
        default:
            throw ImpossibleConversionException();
        }
    }
    // Example '\xff'
    case Conversion::CHAR_HEXA:
    {
        size_t hexVal;
        std::stringstream(_rawString.substr(3, _rawString.size() - 3)) >> std::hex >>
            hexVal;
        if (hexVal >= 32 && hexVal <= 126)
        {
            return (static_cast<char>(hexVal));
        }
        throw NonDisplayableCharacterException();
    }
    // Example '\177'
    case Conversion::CHAR_OCTAL:
    {
        size_t octVal;
        std::stringstream(_rawString.substr(2, _rawString.size() - 2)) >> std::oct >>
            octVal;
        if (octVal >= 32 && octVal <= 126)
        {
            return (static_cast<char>(octVal));
        }
        throw NonDisplayableCharacterException();
    }
    case Conversion::INT:
    {
        size_t intVal;
        std::stringstream(_rawString) >> std::dec >> intVal;
        if (intVal >= 32 && intVal <= 126)
        {
            return (static_cast<char>(intVal));
        }
        if (intVal < 32 || intVal == 127)
        {
            throw NonDisplayableCharacterException();
        }
        throw ImpossibleConversionException();
    }
    case Conversion::FLOAT_PSEUDO:
    {
        throw ImpossibleConversionException();
    }
    case Conversion::FLOAT:
    {
        float floatVal;
        std::stringstream(_rawString.substr(0, _rawString.size() - 1)) >> floatVal;
        if (floatVal >= 32.0f && floatVal <= 126.0f)
        {
            return (static_cast<char>(floatVal));
        }
        if (floatVal < 32.0f || floatVal == 127.0f)
        {
            throw NonDisplayableCharacterException();
        }
        throw ImpossibleConversionException();
    }
    case Conversion::DOUBLE_PSEUDO:
    {
        throw ImpossibleConversionException();
    }
    case Conversion::DOUBLE:
    {
        double doubleVal;
        std::stringstream(_rawString) >> doubleVal;
        if (doubleVal >= 32.0 && doubleVal <= 126.0)
        {
            return (static_cast<char>(doubleVal));
        }
        if (doubleVal < 32.0 || doubleVal == 127.0)
        {
            throw NonDisplayableCharacterException();
        }
        throw ImpossibleConversionException();
    }
    default:
        throw ImpossibleConversionException();
    }
}

int Conversion::getInt(void)
{
    switch (_inputType)
    {
    // Example 'd'
    case Conversion::CHAR_NORMAL:
    {
        return (static_cast<int>(_rawString[1]));
    }
    // Example '\n'
    case Conversion::CHAR_ESCAPE:
    {
        switch (_rawString[2])
        {
        case 'a':
            return (static_cast<int>('\a'));
        case 'b':
            return (static_cast<int>('\b'));
        case 'f':
            return (static_cast<int>('\f'));
        case 'n':
            return (static_cast<int>('\n'));
        case 'r':
            return (static_cast<int>('\r'));
        case 't':
            return (static_cast<int>('\t'));
        case 'v':
            return (static_cast<int>('\v'));
        case '\'':
            return (static_cast<int>('\''));
        case '\\':
            return (static_cast<int>('\\'));
        case '\"':
            return (static_cast<int>('\"'));
        case '?':
            return (static_cast<int>('\?'));
        default:
            throw ImpossibleConversionException();
        }
    }
    // Example '\xff'
    case Conversion::CHAR_HEXA:
    {
        size_t hexVal;
        std::stringstream(_rawString.substr(3, _rawString.size() - 3)) >> std::hex >>
            hexVal;
        return (static_cast<int>(hexVal));
    }
    // Example '\177'
    case Conversion::CHAR_OCTAL:
    {
        size_t octVal;
        std::stringstream(_rawString.substr(2, _rawString.size() - 2)) >> std::oct >>
            octVal;
        return (static_cast<int>(octVal));
    }
    case Conversion::INT:
    {
        int intVal;
        std::stringstream ss(_rawString);
        ss >> std::dec >> intVal;
        if (!ss.fail())
        {
            return (intVal);
        }
        throw ImpossibleConversionException();
    }
    case Conversion::FLOAT_PSEUDO:
    {
        throw ImpossibleConversionException();
    }
    case Conversion::FLOAT:
    {
        std::stringstream ss(_rawString.substr(0, _rawString.size() - 1));
        float floatVal;
        ss >> floatVal;
        if (!ss.fail())
        {
            return (static_cast<int>(floatVal));
        }
        throw ImpossibleConversionException();
    }
    case Conversion::DOUBLE_PSEUDO:
    {
        throw ImpossibleConversionException();
    }
    case Conversion::DOUBLE:
    {
        std::stringstream ss(_rawString.substr(0, _rawString.size() - 1));
        double doubleVal;
        ss >> doubleVal;
        if (!ss.fail())
        {
            return (static_cast<int>(doubleVal));
        }
        throw ImpossibleConversionException();
    }
    default:
        throw ImpossibleConversionException();
    }
}

float Conversion::getFloat(void)
{
    switch (_inputType)
    {
    // Example 'd'
    case Conversion::CHAR_NORMAL:
    {
        return (static_cast<float>(_rawString[1]));
    }
    // Example '\n'
    case Conversion::CHAR_ESCAPE:
    {
        switch (_rawString[2])
        {
        case 'a':
            return (static_cast<float>('\a'));
        case 'b':
            return (static_cast<float>('\b'));
        case 'f':
            return (static_cast<float>('\f'));
        case 'n':
            return (static_cast<float>('\n'));
        case 'r':
            return (static_cast<float>('\r'));
        case 't':
            return (static_cast<float>('\t'));
        case 'v':
            return (static_cast<float>('\v'));
        case '\'':
            return (static_cast<float>('\''));
        case '\\':
            return (static_cast<float>('\\'));
        case '\"':
            return (static_cast<float>('\"'));
        case '?':
            return (static_cast<float>('\?'));
        default:
            throw ImpossibleConversionException();
        }
    }
    // Example '\xff'
    case Conversion::CHAR_HEXA:
    {
        size_t hexVal;
        std::stringstream(_rawString.substr(3, _rawString.size() - 3)) >> std::hex >>
            hexVal;
        return (static_cast<float>(hexVal));
    }
    // Example '\177'
    case Conversion::CHAR_OCTAL:
    {
        size_t octVal;
        std::stringstream(_rawString.substr(2, _rawString.size() - 2)) >> std::oct >>
            octVal;
        return (static_cast<float>(octVal));
    }
    case Conversion::INT:
    {
        float floatVal;
        std::stringstream ss(_rawString);
        ss >> floatVal;
        if (!ss.fail())
        {
            return (floatVal);
        }
        throw ImpossibleConversionException();
    }
    case Conversion::FLOAT_PSEUDO:
    {
        if (_rawString == "nanf")
        {
            return (std::numeric_limits<float>::quiet_NaN());
        }
        if (_rawString == "+inff")
        {
            return (std::numeric_limits<float>::infinity());
        }
        if (_rawString == "-inff")
        {
            return (-std::numeric_limits<float>::infinity());
        }
        throw ImpossibleConversionException();
    }
    case Conversion::FLOAT:
    {
        const std::string floatSubstr = _rawString.substr(0, _rawString.size() - 1);
        float floatVal;
        std::stringstream ss(floatSubstr);
        ss >> floatVal;
        if (!ss.fail())
        {
            return (floatVal);
        }
        throw ImpossibleConversionException();
    }
    case Conversion::DOUBLE_PSEUDO:
    {
        if (_rawString == "nan")
        {
            return (std::numeric_limits<float>::quiet_NaN());
        }
        if (_rawString == "+inf")
        {
            return (std::numeric_limits<float>::infinity());
        }
        if (_rawString == "-inf")
        {
            return (-std::numeric_limits<float>::infinity());
        }
        throw ImpossibleConversionException();
    }
    case Conversion::DOUBLE:
    {
        float floatVal;
        std::stringstream ss(_rawString);
        ss >> floatVal;
        if (!ss.fail())
        {
            return (floatVal);
        }
        throw ImpossibleConversionException();
    }
    default:
        throw ImpossibleConversionException();
    }
}

double Conversion::getDouble(void)
{
    switch (_inputType)
    {
    // Example 'd'
    case Conversion::CHAR_NORMAL:
    {
        return (static_cast<double>(_rawString[1]));
    }
    // Example '\n'
    case Conversion::CHAR_ESCAPE:
    {
        switch (_rawString[2])
        {
        case 'a':
            return (static_cast<double>('\a'));
        case 'b':
            return (static_cast<double>('\b'));
        case 'f':
            return (static_cast<double>('\f'));
        case 'n':
            return (static_cast<double>('\n'));
        case 'r':
            return (static_cast<double>('\r'));
        case 't':
            return (static_cast<double>('\t'));
        case 'v':
            return (static_cast<double>('\v'));
        case '\'':
            return (static_cast<double>('\''));
        case '\\':
            return (static_cast<double>('\\'));
        case '\"':
            return (static_cast<double>('\"'));
        case '?':
            return (static_cast<double>('\?'));
        default:
            throw ImpossibleConversionException();
        }
    }
    // Example '\xff'
    case Conversion::CHAR_HEXA:
    {
        size_t hexVal;
        std::stringstream(_rawString.substr(3, _rawString.size() - 3)) >> std::hex >>
            hexVal;
        return (static_cast<double>(hexVal));
    }
    // Example '\177'
    case Conversion::CHAR_OCTAL:
    {
        size_t octVal;
        std::stringstream(_rawString.substr(2, _rawString.size() - 2)) >> std::oct >>
            octVal;
        return (static_cast<double>(octVal));
    }
    case Conversion::INT:
    {
        double doubleVal;
        std::stringstream ss(_rawString);
        ss >> doubleVal;
        if (!ss.fail())
        {
            return (doubleVal);
        }
        throw ImpossibleConversionException();
    }
    case Conversion::FLOAT_PSEUDO:
    {
        if (_rawString == "nanf")
        {
            return (std::numeric_limits<double>::quiet_NaN());
        }
        if (_rawString == "+inff")
        {
            return (std::numeric_limits<double>::infinity());
        }
        if (_rawString == "-inff")
        {
            return (-std::numeric_limits<double>::infinity());
        }
        throw ImpossibleConversionException();
    }
    case Conversion::FLOAT:
    {
        const std::string floatSubstr = _rawString.substr(0, _rawString.size() - 1);
        double doubleVal;
        std::stringstream ss(floatSubstr);
        ss >> doubleVal;
        if (!ss.fail())
        {
            return (doubleVal);
        }
        throw ImpossibleConversionException();
    }
    case Conversion::DOUBLE_PSEUDO:
    {
        if (_rawString == "nan")
        {
            return (std::numeric_limits<double>::quiet_NaN());
        }
        if (_rawString == "+inf")
        {
            return (std::numeric_limits<double>::infinity());
        }
        if (_rawString == "-inf")
        {
            return (-std::numeric_limits<double>::infinity());
        }
        throw ImpossibleConversionException();
    }
    case Conversion::DOUBLE:
    {
        double doubleVal;
        std::stringstream ss(_rawString);
        ss >> doubleVal;
        if (!ss.fail())
        {
            return (doubleVal);
        }
        throw ImpossibleConversionException();
    }
    default:
        throw ImpossibleConversionException();
    }
}

bool Conversion::_isDigit(const char ch)
{
    const std::string digits = "0123456789";
    return (digits.find(ch) != std::string::npos);
}

// Dummy destructor
Conversion::~Conversion(void) {}