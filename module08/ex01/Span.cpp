/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:00:28 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 00:38:59 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Creates a default Span with a maximum of 10 numbers
Span::Span(void) : _nums(), _maxNums(10), _isSorted(true) {}

Span::Span(unsigned int n) : _nums(), _maxNums(n), _isSorted(true) {}

Span::Span(const Span &old)
    : _nums(old._nums), _maxNums(old._maxNums), _isSorted(old._isSorted)
{
}

Span &Span::operator=(const Span &rhs)
{
    if (this == &rhs)
    {
        return (*this);
    }
    _nums = rhs._nums;
    _maxNums = rhs._maxNums;
    _isSorted = rhs._isSorted;
    return (*this);
}

void Span::addNumber(unsigned int num)
{
    if (_nums.size() < _maxNums)
    {
        _nums.push_back(num);
        if (_nums.size() > 1)
        {
            _isSorted = false;
        }
    }
    else
    {
        throw std::length_error("Span is full");
    }
}

unsigned int Span::shortestSpan(void)
{
    if (_nums.size() < 2)
    {
        throw std::length_error("Span has less than 2 elements");
    }
    if (_isSorted == false)
    {
        std::sort(_nums.begin(), _nums.end());
        _isSorted = true;
    }
    std::vector<unsigned int> diffs;
    for (std::vector<unsigned int>::iterator it = _nums.begin(); it != _nums.end() - 1; it++)
    {
        diffs.push_back(*(it + 1) - *it);
    }
    return (*std::min_element(diffs.begin(), diffs.end()));
}

unsigned int Span::longestSpan(void)
{
    if (_nums.size() < 2)
    {
        throw std::length_error("Span has less than 2 elements");
    }
    if (_isSorted == false)
    {
        std::sort(_nums.begin(), _nums.end());
        _isSorted = true;
    }
    return (*(_nums.end() - 1) - *_nums.begin());
}

Span::~Span(void) {}
