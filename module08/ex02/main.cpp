/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:20:23 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/26 02:28:49 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>
int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    mstack.push(2);
    mstack.push(7);
    mstack.push(3);
    mstack.push(80);
    mstack.push(90);
    mstack.pop();
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // List
    std::cout << std::endl;
    std::list<int> mList;
    mList.push_back(5);
    mList.push_back(17);
    std::cout << mList.back() << std::endl;
    mList.pop_back();
    std::cout << mList.size() << std::endl;
    mList.push_back(3);
    mList.push_back(5);
    mList.push_back(737);
    mList.push_back(0);
    mList.push_back(2);
    mList.push_back(7);
    mList.push_back(3);
    mList.push_back(80);
    mList.push_back(90);
    mList.pop_back();
    std::list<int>::iterator it2 = mList.begin();
    std::list<int>::iterator ite2 = mList.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    return 0;
}