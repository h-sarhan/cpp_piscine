/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:38:23 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 08:21:23 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL
#define HARL

#include <cstdlib>
#include <iostream>
#include <string>

class Harl
{
public:
    void complain(std::string level);

private:
    typedef void (Harl::*log_func)(void);
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void invalidArg(void);
    static std::string states[4];
    static log_func funcs[5];
    static log_func strToLogFunc(const std::string &str);
};
#endif