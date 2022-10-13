/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:52:51 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/13 10:57:28 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA
#define AMATERIA

#include "ICharacter.hpp"
#include <iostream>
#include <string>
class ICharacter;

class AMateria
{
protected:
    std::string materiaType;

public:
    AMateria(void);
    AMateria(const std::string &type);

    AMateria(const AMateria &old);
    AMateria &operator=(const AMateria &rhs);
    virtual ~AMateria(void);

    const std::string &getType(void) const;

    virtual AMateria *clone(void) const = 0;
    virtual void use(ICharacter &target);
};
#endif
