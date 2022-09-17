/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:35:44 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/17 23:32:52 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	: _name("default"), _grade(150)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const size_t grade)
	: _name(name), _grade(grade)
{
	std::cout << "Named Bureaucrat constructor called" << std::endl;
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else if (grade < 1)
	{
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &old)
	: _name(old._name), _grade(old._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat copy assignment constructor called" << std::endl;
	if (&rhs == this)
		return (*this);
	*this = Bureaucrat(rhs);
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string &Bureaucrat::getName(void) const
{
	return (_name);
}

size_t Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade < 1)
	{
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade > 150)
	{
		throw GradeTooLowException();
	}
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureacrat grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureacrat grade too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

void Bureaucrat::signForm(Form& form)
{
	form.beSigned(*this);
	if (form.getSigned() == false)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << "<FILL THIS IN LATER>" << std::endl;
	}
	else
	{
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form& form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception)
	{
		std::cerr << "Could not execute form" << std::endl;
	}
}
