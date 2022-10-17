/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:19:47 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/17 15:11:49 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND
#define EASY_FIND

#include <algorithm>
#include <iterator>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T nums, int toFind)
{
    typename T::iterator res = find(begin(nums), end(nums), toFind);
    if (res == end(nums))
        throw std::invalid_argument("Argument not found");
    return (res);
}

#endif