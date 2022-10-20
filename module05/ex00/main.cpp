/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:50:52 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 10:15:31 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b = Bureaucrat("bob", 150);
		std::cout << b;
		Bureaucrat d = Bureaucrat("david", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}