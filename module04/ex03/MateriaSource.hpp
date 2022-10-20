/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:24:25 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 09:37:56 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE
#define MATERIA_SOURCE

#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
public:
    MateriaSource(void);
    MateriaSource(const MateriaSource &old);
    MateriaSource &operator=(const MateriaSource &rhs);
    ~MateriaSource(void);

    void learnMateria(AMateria *materia);
    AMateria *createMateria(const std::string &type);

private:
    AMateria *_learnedMateria[4];
    unsigned int _materiaIdx;
};
#endif
