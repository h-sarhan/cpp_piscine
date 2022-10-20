/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:47:05 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 14:38:16 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) { std::cout << "Calling default Intern constructor" << std::endl; }

Intern::Intern(const Intern &old)
{
    (void)old;
    std::cout << "Calling Intern copy constructor" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    std::cout << "Calling Intern copy assignment constructor" << std::endl;
    return (*this);
}

Intern::~Intern(void) { std::cout << "Calling Intern destructor" << std::endl; }

Form *Intern::makeForm(const std::string &formName, const std::string &target)
{
    for (size_t i = 0; i < 3; i++)
    {
        if (forms[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*formFuncs[i])(target));
        }
    }
    std::cout << "Form does not exist." << std::endl;
    return (0);
}

Form *Intern::makePresidentialForm(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

Form *Intern::makeRobotomyForm(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

Form *Intern::makeShrubberyForm(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

std::string Intern::forms[] = {"presidential pardon", "robotomy request",
                               "shrubbery creation"};

Intern::formCreationFunc Intern::formFuncs[] = {
    &Intern::makePresidentialForm, &Intern::makeRobotomyForm, &Intern::makeShrubberyForm};