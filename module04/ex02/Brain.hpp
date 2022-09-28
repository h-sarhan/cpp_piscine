/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:16:09 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/28 16:18:29 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN
#define BRAIN

#include <string>
#include <iostream>
#include <cstdlib>

class Brain
{
public:
	Brain(void);
	Brain(const Brain &old);
	Brain &operator=(const Brain &rhs);
	~Brain(void);

	void	printFiveThoughts(void) const;
private:
	std::string ideas[100];
	static const std::string ideaList[];
};

#endif