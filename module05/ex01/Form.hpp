/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:46:44 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/16 14:16:19 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM
#define FORM

#include <string>
#include <iostream>

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
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

	// void beSigned() const;

private:
	const std::string _name;
	bool _signed;
	size_t _signingGrade;
	size_t _executionGrade;
};

#endif