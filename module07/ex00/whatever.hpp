/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:12:00 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/14 15:10:51 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T> void swap(T &a, T &b)
{
    T	temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T> T &min(T &a,T &b)
{
    if (a < b)
        return (a);
    return (b);
}

template <typename T> T &max(T &a, T &b)
{
    if (a > b)
        return (a);
    return (b);
}
