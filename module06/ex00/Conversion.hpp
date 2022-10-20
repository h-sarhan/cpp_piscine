/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:58:24 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 15:06:04 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION
#define CONVERSION

#include <string>

class Conversion
{
public:
	Conversion(void);
	Conversion(const std::string &str);
	Conversion(const Conversion &old);
	Conversion &operator=(const Conversion &rhs);
	~Conversion(void);
	std::string	getChar(void);
	std::string	getInt(void);
	std::string	getFloat(void);
	std::string	getDouble(void);
};

#endif