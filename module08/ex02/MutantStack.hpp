/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:20:42 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/25 22:45:12 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <stack>
#include <iterator>
template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typename std::stack<T>::container_type::iterator begin()
	{
		return (std::stack<T>::c.begin());
	}

	typename std::stack<T>::container_type::iterator end()
	{
		return (std::stack<T>::c.end());
	}
};
#endif