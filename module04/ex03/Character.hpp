/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:37:02 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 09:37:59 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER
#define CHARACTER

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <cstddef>

class Character : public ICharacter
{
public:
    Character(void);
    Character(const std::string &name);
    Character(const Character &old);
    Character &operator=(const Character &rhs);
    ~Character(void);

    const std::string &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

private:
    AMateria *_inventory[4];
    bool _equipped[4];
    std::string _name;
};
#endif
