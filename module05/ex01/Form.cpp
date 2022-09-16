/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:46:38 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/16 14:15:33 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: _name("default"),
	  _signed(false),
	  _signingGrade(10),
	  _executionGrade(10)
{
	std::cout << "Default form constructor called" << std::endl;
}

Form::Form(const std::string name, const size_t signingGrade, const size_t executionGrade)
	: _name(name),
	  _signed(false),
	  _signingGrade(signingGrade),
	  _executionGrade(executionGrade)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &old)
	: _name(old._name),
	  _signed(old._signed),
	  _signingGrade(old._signingGrade),
	  _executionGrade(old._executionGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << "Form copy assignment constructor called" << std::endl;
	if (this == &rhs)
	{
		return (*this);
	}
	*this = Form(rhs._name, rhs._signingGrade, rhs._executionGrade);
	this->_signed = rhs._signed;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Bureacrat grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Bureacrat grade too low");
}
