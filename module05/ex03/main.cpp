/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:50:52 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 14:37:39 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern someRandomIntern;
    Form *rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    Bureaucrat b = Bureaucrat("benjamin", 1);
    b.signForm(*rrf);
    b.executeForm(*rrf);
    delete rrf;
}