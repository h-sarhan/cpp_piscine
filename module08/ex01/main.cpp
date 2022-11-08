/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:00:22 by hsarhan           #+#    #+#             */
/*   Updated: 2022/11/08 19:37:37 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <cstdlib>
#include <iostream>
#include <list>
int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Normal example" << std::endl;
    std::cout << "Shortest span " << sp.shortestSpan() << std::endl;
    std::cout << "Langest span " << sp.longestSpan() << std::endl;

    // Lots of numbers
    Span sp2 = Span(200000);
    srand(time(NULL));
    for (unsigned int i = 0; i < 200000; i++)
    {
        sp2.addNumber(rand() % 400000000);
    }
    std::cout << std::endl << "Lots of numbers" << std::endl;
    std::cout << "Shortest span " << sp2.shortestSpan() << std::endl;
    std::cout << "Langest span " <<  sp2.longestSpan() << std::endl;

    // Similar numbers
    Span sp3 = Span(10);
    sp3.addNumber(6);
    sp3.addNumber(6);
    sp3.addNumber(3);
    sp3.addNumber(9);
    sp3.addNumber(3);
    sp3.addNumber(3);
    sp3.addNumber(8);
    std::cout << std::endl << "Similar numbers" << std::endl;
    std::cout << "Shortest span " <<sp3.shortestSpan() << std::endl;
    std::cout << "Langest span " << sp3.longestSpan() << std::endl;

    // Exception handling
    std::cout << std::endl << "Exception handling" << std::endl;
    Span sp4 = Span(1);
    try
    {
        sp4.addNumber(1);
        sp4.addNumber(3);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Span sp5 = Span(1);
    try
    {
        sp5.addNumber(1);
        std::cout << sp5.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    // Iterator constructor
    std::cout << std::endl << "Iterator constructor" << std::endl;

    std::list<unsigned int> lst;
    lst.push_back(3);
    lst.push_back(1);
    lst.push_back(19);
    lst.push_back(19);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(2);
    lst.push_back(6);
    Span sp6 = Span(8);
    sp6.addNumber(lst.begin(), lst.end());
    std::cout << "Shortest span " << sp6.shortestSpan() << std::endl;
    std::cout << "Langest span " <<  sp6.longestSpan() << std::endl;

    try
    {
        Span sp7 = Span(7);
        sp6.addNumber(lst.begin(), lst.end());
        std::cout << "Shortest span " << sp6.shortestSpan() << std::endl;
        std::cout << "Langest span " <<  sp6.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }


    return 0;
}