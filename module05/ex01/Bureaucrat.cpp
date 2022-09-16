/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:35:44 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/16 12:51:18 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	: name("default"), _grade(150)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const size_t grade)
	: name(name), _grade(grade)
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
	: name(old.name), _grade(old._grade)
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
	return (name);
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
}
