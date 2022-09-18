/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 07:59:13 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:49:52 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPTR = &str;
    std::string &strREF = str;

    std::cout << "str address: " << &str << std::endl;
    std::cout << "strPTR address: " << strPTR << std::endl;
    std::cout << "strREF address: " << &strREF << std::endl;
    std::cout << std::endl;

    std::cout << "str value: " << str << std::endl;
    std::cout << "strPTR value: " << *strPTR << std::endl;
    std::cout << "strREF value: " << strREF << std::endl;
}