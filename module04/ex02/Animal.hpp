/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:29:34 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 08:43:47 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL
#define ANIMAL

#include <iostream>

class Animal
{
public:
	Animal(void);
	Animal(const Animal& old);
	Animal& operator=(const Animal& rhs);
	virtual ~Animal(void);

	virtual void makeSound(void) const = 0;
	const std::string& getType(void) const;
protected:
	std::string type;
};
#endif