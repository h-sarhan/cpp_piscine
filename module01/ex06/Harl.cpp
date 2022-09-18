/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:48:29 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 08:24:41 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
              << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl
              << "You didn't put enough bacon in my burger! If you did, I wouldn't be "
                 "asking for more!"
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout
        << "I think I deserve to have some extra bacon for free." << std::endl
        << "I've been coming for years whereas you started working here since last month."
        << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::invalidArg(void)
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

Harl::log_func Harl::strToLogFunc(const std::string &str)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (states[i] == str)
            return (Harl::funcs[i]);
    }
    return (Harl::funcs[4]);
}

void Harl::complain(std::string level)
{
    log_func func = Harl::strToLogFunc(level);
    (this->*func)();
    std::cout << std::endl;
}

Harl::LogType Harl::strToLogType(const std::string &str)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (states[i] == str)
            return (static_cast<Harl::LogType>(i));
    }
    return (Harl::INVALID);
}

std::string Harl::states[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
Harl::log_func Harl::funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,
                                &Harl::invalidArg};