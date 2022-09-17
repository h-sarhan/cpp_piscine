/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:46:44 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/17 17:02:56 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM
#define FORM


#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

// ! Write getters and setters
class Form
{
public:
	Form(void);
	Form(const std::string name, const size_t signingGrade, const size_t executionGrade);
	Form(const Form &old);
	Form &operator=(const Form &rhs);
	~Form(void);

	class GradeTooHighException : public std::exception
	{
		const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what(void) const throw();
	};

	const std::string& getName(void) const;
	bool getSigned(void) const;
	size_t getSigningGrade(void) const;
	size_t getExecutionGrade(void) const;

	void beSigned(const Bureaucrat& bureaucrat);

private:
	const std::string _name;
	bool _signed;
	const size_t _signingGrade;
	const size_t _executionGrade;
};

#endif