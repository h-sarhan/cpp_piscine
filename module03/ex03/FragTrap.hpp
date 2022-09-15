/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 03:51:56 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 06:51:36 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP
#define FRAG_TRAP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const std::string& name);
	FragTrap(const FragTrap &old);
	FragTrap &operator=(const FragTrap &rhs);
	~FragTrap(void);

	void highFivesGuys(void);
	void attack(const std::string& target);
protected:
	unsigned int _hp;
	unsigned int _energy;
	unsigned int _damage;
};

#endif

