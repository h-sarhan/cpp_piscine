/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:12:06 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/13 10:57:39 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE
#define ICE

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria
{
public:
    Ice(void);

    Ice(const Ice &old);
    Ice &operator=(const Ice &rhs);
    ~Ice(void);

    AMateria *clone(void) const;
    void use(ICharacter &target);
};
#endif
