/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:29:34 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 07:57:37 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT
#define CAT

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat& old);
	Cat& operator=(const Cat& rhs);
	virtual ~Cat(void);

	void makeSound(void) const;
};
#endif