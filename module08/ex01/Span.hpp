/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:00:38 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 00:37:36 by hsarhan          ###   ########.fr       */
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
	template<typename InputIt>
	Span(InputIt first, InputIt last);
    Span &operator=(const Span &rhs);

    void addNumber(unsigned int num);
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);
    ~Span(void);

private:
    std::vector<unsigned int> _nums;
    unsigned int _maxNums;
	bool		_isSorted;
};

template<typename InputIt>
Span::Span(InputIt first, InputIt last)
    : _nums(), _isSorted(false)
{
    for (InputIt it = first; it != last; it++)
    {
		_nums.push_back(*it);
    }
	_maxNums = _nums.size();
}
#endif