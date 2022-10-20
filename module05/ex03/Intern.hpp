/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:47:24 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/20 14:38:21 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN
#define INTERN

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Intern
{
public:
    typedef Form *(Intern::*formCreationFunc)(const std::string &target);

    Intern(void);
    Intern(const Intern &old);
    Intern &operator=(const Intern &rhs);
    ~Intern(void);
    Form *makeForm(const std::string &formName, const std::string &target);

private:
    Form *makePresidentialForm(const std::string &target);
    Form *makeRobotomyForm(const std::string &target);
    Form *makeShrubberyForm(const std::string &target);
    static std::string forms[3];
    static formCreationFunc formFuncs[3];
};
#endif