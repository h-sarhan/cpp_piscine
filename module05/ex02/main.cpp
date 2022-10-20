/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:50:52 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 11:40:54 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat b = Bureaucrat("bob", 137);
	Bureaucrat c = Bureaucrat("christina", 1);
	ShrubberyCreationForm shrubForm("shrubs");
	RobotomyRequestForm robotomyForm("Elliot");
	PresidentialPardonForm presForm("Jon");

	// Cannot execute without signing
	b.executeForm(shrubForm);

	// Shrubbery form
	b.signForm(shrubForm);
	b.executeForm(shrubForm);

	// Robotomy form
	c.signForm(robotomyForm);
	c.executeForm(robotomyForm);

	// Grade too low
	b.signForm(presForm);
	b.executeForm(presForm);

	// Presidential pardon form
	c.signForm(presForm);
	c.executeForm(presForm);
}