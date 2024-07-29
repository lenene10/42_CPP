/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:29:02 by rluari            #+#    #+#             */
/*   Updated: 2024/04/22 18:49:57 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AForm;

class Bureaucrat
{
    const std::string Name;
    int Grade;

    public:
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(std::string const &name);
        Bureaucrat(Bureaucrat const &src);
        ~Bureaucrat();
        Bureaucrat &operator=(Bureaucrat const &rhs);
    
        const std::string getName() const;
        int getGrade() const;
        void setGrade(int grade);
        void incrementGrade();  //e.g. 3 becomes 2
        void decrementGrade();  //opposite

        void signForm(AForm& f);
        void executeForm(AForm const & form);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);