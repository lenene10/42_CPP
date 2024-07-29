/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:51:46 by rluari            #+#    #+#             */
/*   Updated: 2024/04/12 12:01:54 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const & src)
{
    *this = src;
}

Intern& Intern::operator=(Intern const & rhs)
{
    (void)rhs;
    return *this;
}

Intern::~Intern()
{}

//methods

AForm	*makePresidentForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*makeRobotForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*makeShrubberyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm   *Intern::makeForm(const std::string FormName, const std::string TargetName)
{
    AForm *(*form_func[])(const std::string target) = {&makeShrubberyForm, &makeRobotForm, &makePresidentForm};
    std::string form_types[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (int i = 0; i < 3; i++)
	{
		if (FormName == form_types[i])
		{
			std::cout << "Intern creates " << FormName << std::endl;
			return (form_func[i](TargetName));
		}
	}
	std::cout << "Intern could not create " << FormName << " because: ";
	throw FormNotFoundException();
}
