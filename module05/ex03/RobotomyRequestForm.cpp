/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:45:40 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 00:06:00 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("Robotomy Request Form", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& old)
	: Form(old), _target(old._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "RobotomyRequestForm copy assignment constructor called" << std::endl;
	if (this == &rhs)
	{
		return (*this);
	}
	setSigned(rhs.getSigned());
	_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (getSigned() == true && executor.getGrade() <= getExecutionGrade())
	{
		std::cout << "<DRILLING NOISES~~~~~~~~~~~~~~~~~~~~~~>" << std::endl;
		std::srand(time(NULL));
		if (std::rand() % 2 == 0)
		{
			std::cout << "Robotomy successful" << std::endl;
		}
		else
		{
			std::cout << "Robotomy has failed" << std::endl;
		}
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
