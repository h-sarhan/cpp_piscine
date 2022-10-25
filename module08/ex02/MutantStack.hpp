/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:20:42 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/26 02:28:47 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <iterator>
#include <stack>
template <typename T> class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
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