/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:45:40 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 00:13:21 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("Presidential Pardon Form", 72, 45), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form("Presidential Pardon Form", 72, 45), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& old)
	: Form(old), _target(old._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "PresidentialPardonForm copy assignment constructor called" << std::endl;
	if (this == &rhs)
	{
		return (*this);
	}
	setSigned(rhs.getSigned());
	_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (getSigned() == true && executor.getGrade() <= getExecutionGrade())
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
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
