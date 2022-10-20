/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:35:44 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 10:32:01 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
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

Bureaucrat::Bureaucrat(const Bureaucrat &old) : _name(old._name), _grade(old._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    std::cout << "Bureaucrat copy assignment constructor called" << std::endl;
    if (&rhs == this)
        return (*this);
    this->_grade = rhs._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string &Bureaucrat::getName(void) const { return (_name); }

size_t Bureaucrat::getGrade(void) const { return (_grade); }

void Bureaucrat::incrementGrade(void)
{
    if (_grade <= 1)
    {
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (_grade >= 150)
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


void Bureaucrat::signForm(Form& form)
{
    try
    {
    	form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "."
       << std::endl;
    return (os);
}