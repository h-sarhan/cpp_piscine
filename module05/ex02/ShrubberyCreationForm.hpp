/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:42:31 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/17 23:45:01 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& old);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm(void);
	
	void execute(const Bureaucrat& executor) const;

private:
	std::string _target;
};

#endif