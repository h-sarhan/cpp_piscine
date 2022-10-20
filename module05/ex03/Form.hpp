/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:46:44 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/18 00:01:40 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM
#define FORM


#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(const std::string name, const size_t signingGrade, const size_t executionGrade);
	Form(const Form &old);
	Form &operator=(const Form &rhs);
	virtual ~Form(void);

	class GradeTooHighException : public std::exception
	{
		const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char *what(void) const throw();
	};
	
	class FormNotSignedException : public std::exception
	{
		const char *what(void) const throw();
	};

	const std::string& getName(void) const;
	bool getSigned(void) const;
	size_t getSigningGrade(void) const;
	size_t getExecutionGrade(void) const;
	
	void beSigned(const Bureaucrat& bureaucrat);

	void setSigned(bool val);
	virtual void execute(const Bureaucrat& executor) const = 0;

private:
	const std::string _name;
	bool _signed;
	const size_t _signingGrade;
	const size_t _executionGrade;
};

#endif