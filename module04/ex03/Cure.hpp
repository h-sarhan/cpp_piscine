/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:24:48 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/13 11:25:12 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE
#define CURE

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria
{
public:
    Cure(void);

    Cure(const Cure &old);
    Cure &operator=(const Cure &rhs);
    ~Cure(void);

    AMateria *clone(void) const;
    void use(ICharacter &target);
};
#endif
