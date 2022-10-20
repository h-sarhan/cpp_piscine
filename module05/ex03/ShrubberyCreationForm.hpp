/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:42:31 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 11:29:51 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


#define TREE "               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | | \n\
       |.|        | |         | | \n\
     \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_"

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