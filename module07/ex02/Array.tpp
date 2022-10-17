/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:15:10 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/17 13:51:29 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> Array<T>::Array(void) : _size(0), _arr(NULL) {}

template <typename T> Array<T>::Array(unsigned int n) : _size(n), _arr(new T[n]) {}

template <typename T> Array<T>::Array(const Array<T> &old) : _size(old.size())
{
    for (unsigned int i = 0; i < old.size(); i++)
    {
        _arr[i] = old[i];
    }
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    if (&rhs == this)
    {
        return (*this);
    }
    delete[] _arr;
    _arr = new T[rhs.size()];
    _size = rhs.size();
    for (unsigned int i = 0; i < rhs.size(); i++)
    {
        _arr[i] = rhs[i];
    }
    return (*this);
}

template <typename T> Array<T>::~Array(void) { delete[] _arr; }

template <typename T> T &Array<T>::operator[](unsigned int idx) const
{
    if (idx < 0 || idx >= _size)
        throw std::out_of_range("Index out of range");
    return (_arr[idx]);
}

template <typename T> unsigned int Array<T>::size() const { return (_size); }