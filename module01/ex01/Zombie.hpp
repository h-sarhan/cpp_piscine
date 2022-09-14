/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:04:07 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/14 12:03:13 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE

#include <string>
#include <iostream>

// ! zombieHorde has to be outside the Zombie class

class Zombie
{
public:
	Zombie(void);
	Zombie(std::string name);
	void announce(void);
	Zombie *zombieHorde(int N, std::string name);
	~Zombie(void);

private:
	std::string name;
};

#endif