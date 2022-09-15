/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 07:29:34 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 08:02:47 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL
#define WRONG_ANIMAL

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& old);
	WrongAnimal& operator=(const WrongAnimal& rhs);
	virtual ~WrongAnimal(void);

	void makeSound(void) const;
	const std::string& getType(void) const;
protected:
	std::string type;
};
#endif