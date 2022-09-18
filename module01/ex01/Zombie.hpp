/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:04:07 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:48:30 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>
#include <string>

class Zombie
{
public:
    Zombie(void);
    Zombie(std::string name);
    void announce(void);
    ~Zombie(void);

    void setName(const std::string &name);

private:
    std::string _name;
};

Zombie *zombieHorde(int N, std::string name);
#endif