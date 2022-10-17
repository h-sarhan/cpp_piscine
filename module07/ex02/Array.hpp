/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:50:23 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/17 13:51:22 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY
#define ARRAY

#include <stdexcept>
template <class T> class Array
{
public:
    Array(void);
    Array(unsigned int n);

    Array(const Array &old);
    Array &operator=(const Array &rhs);
    ~Array(void);

    T &operator[](unsigned int idx) const;
    unsigned int size() const;

private:
    unsigned int _size;
    T *_arr;
};
#include "Array.tpp"
#endif