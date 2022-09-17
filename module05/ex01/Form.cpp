/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:46:38 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/17 18:49:28 by hsarhan          ###   ########.fr       */
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
	if (_signingGrade < 1)
	{
		throw GradeTooHighException();
	}
	else if (_signingGrade > 150)
	{
		throw GradeTooLowException();
	}
	if (_executionGrade < 1)
	{
		throw GradeTooHighException();
	}
	else if (_executionGrade > 150)
	{
		throw GradeTooLowException();
	}
}

Form::Form(const std::string name, const size_t signingGrade, const size_t executionGrade)
	: _name(name),
	  _signed(false),
	  _signingGrade(signingGrade),
	  _executionGrade(executionGrade)
{
	std::cout << "Form constructor called" << std::endl;
	if (_signingGrade < 1)
	{
		throw GradeTooHighException();
	}
	else if (_signingGrade > 150)
	{
		throw GradeTooLowException();
	}
	if (_executionGrade < 1)
	{
		throw GradeTooHighException();
	}
	else if (_executionGrade > 150)
	{
		throw GradeTooLowException();
	}
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
	return ("Form grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() >= _signingGrade)
	{
		_signed = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

const std::string &Form::getName(void) const
{
	return (_name);
}

bool Form::getSigned(void) const
{
	return (_signed);
}

size_t Form::getSigningGrade(void) const
{
	return (_signingGrade);
}

size_t Form::getExecutionGrade(void) const
{
	return (_executionGrade);
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form name: " << form.getName() << std::endl
	   << "Is form signed?: " << form.getSigned() << std::endl
	   << "Form execution grade: " << form.getExecutionGrade() << std::endl
	   << "Form signing grade: " << form.getSigningGrade() << std::endl;
	return (os);
}
