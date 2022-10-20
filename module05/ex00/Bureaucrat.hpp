/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:30:25 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 10:12:44 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
public:
    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

    Bureaucrat(void);
    Bureaucrat(const std::string name, const size_t grade);
    Bureaucrat(const Bureaucrat &old);
    Bureaucrat &operator=(const Bureaucrat &rhs);
    ~Bureaucrat(void);

    const std::string &getName(void) const;
    size_t getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);

private:
    const std::string _name;
    size_t _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
