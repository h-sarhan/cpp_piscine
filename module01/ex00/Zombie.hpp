/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:04:07 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/09 02:11:54 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE

#include <string>
#include <iostream>

class Zombie
{
public:
	Zombie(std::string name);
	void announce(void);
	Zombie *newZombie(std::string name);
	void randomChump(std::string name);
	~Zombie(void);

private:
	std::string name;
};

#endif