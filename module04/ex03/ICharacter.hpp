/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:55:28 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/13 10:57:21 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER
# define ICHARACTER
#include "AMateria.hpp"
#include <string>

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter(void);
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};
#endif