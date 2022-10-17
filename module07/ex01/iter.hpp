/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:26:36 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/17 12:14:38 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER
#define ITER
template <typename T> void iter(T arr[], unsigned int len, void (*f)(T item))
{
	for (unsigned int i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}
#endif