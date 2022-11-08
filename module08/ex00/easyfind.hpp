/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:19:47 by hsarhan           #+#    #+#             */
/*   Updated: 2022/11/08 17:34:30 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND
#define EASY_FIND

#include <iterator>
#include <algorithm>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &nums, int toFind)
{
    typename T::iterator res = std::find(nums.begin(), nums.end(), toFind);
    if (res == nums.end())
        throw std::invalid_argument("Argument not found");
    return (res);
}

#endif