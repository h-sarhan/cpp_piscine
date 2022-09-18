/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:16:02 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 07:48:11 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "Creating stack zombie" << std::endl;
    Zombie stackZomb("stack");

    stackZomb.announce();

    std::cout << "Creating random chump" << std::endl;
    randomChump("Random stack zombie");

    std::cout << "Creating heap zombie" << std::endl;
    Zombie *heapZomb = newZombie("heap");
    heapZomb->announce();

    delete heapZomb;
    return (0);
}