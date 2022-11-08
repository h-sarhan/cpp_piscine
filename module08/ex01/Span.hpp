/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:00:38 by hsarhan           #+#    #+#             */
/*   Updated: 2022/11/08 19:38:15 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN
#define SPAN

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span
{
public:
    Span(void);
    Span(unsigned int n);
    Span(const Span &old);
    Span &operator=(const Span &rhs);

    void addNumber(unsigned int num);
	template<typename InputIt>
    void addNumber(InputIt first, InputIt last);
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);
    ~Span(void);

private:
    std::vector<unsigned int> _nums;
    unsigned int _maxNums;
	bool		_isSorted;
};

template<typename InputIt>
void Span::addNumber(InputIt first, InputIt last)
{
    if (std::distance(first, last) + _nums.size() > _maxNums)
    {
        throw std::length_error("Span is full");
    }
    for (InputIt it = first; it != last; it++)
    {
		_nums.push_back(*it);
    }
    if (_nums.size() > 1)
    {
        _isSorted = false;
    }
}
#endif