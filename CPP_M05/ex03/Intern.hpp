/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:48:56 by rluari            #+#    #+#             */
/*   Updated: 2024/04/22 16:42:39 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const & src);
        Intern & operator=(Intern const & rhs);
        ~Intern();

        AForm *makeForm(const std::string FormName, const std::string TargetName);

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form not found");
                }
        };
};