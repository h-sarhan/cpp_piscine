/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:04:07 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:39:55 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>
#include <string>

class Zombie
{
public:
    Zombie(std::string name);
    void announce(void);
    ~Zombie(void);

private:
    std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif