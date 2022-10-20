/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:45:40 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 11:26:56 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("Shrubbery Creation Form", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& old)
	: Form(old), _target(old._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << "ShrubberyCreationForm copy assignment constructor called" << std::endl;
	if (this == &rhs)
	{
		return (*this);
	}
	setSigned(rhs.getSigned());
	_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (getSigned() == true && executor.getGrade() <= getExecutionGrade())
	{
		std::ofstream file;
		file.open((_target + "_shrubbery").c_str());
		file << TREE << std::endl;
		file.close();
	}
	else if (executor.getGrade() <= getExecutionGrade())
	{
		throw GradeTooLowException();
	}
	else
	{
		throw FormNotSignedException();
	}
}
