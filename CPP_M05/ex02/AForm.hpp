/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:27:00 by rluari            #+#    #+#             */
/*   Updated: 2024/04/11 15:09:47 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class AForm{
    bool                _signed;
    const std::string   _formname;
    const int           _min_grade_to_sign;
    const int           _min_grade_to_execute;
    public:
        AForm();
        AForm(std::string name, int min_sign, int min_exec);
        AForm(const AForm& other);
        AForm &operator=(const AForm& other);
        virtual ~AForm();
        
        const std::string getName() const;
        bool getSigned() const;
        int getMinGradeToSign() const;
        int getMinGradeToExecute() const;


        void    beSigned(Bureaucrat &b);

        virtual void execute(Bureaucrat const & executor) const = 0;

        //exceptions
        
        class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
        };

        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class FormAlreadySignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
        /*class GradeTooLowException : public std::exception {
            Bureaucrat &b;
            Form &f;
            std::string s;
            public:
                ~GradeTooLowException() throw();
                GradeTooLowException(Bureaucrat &b, Form &f);
                virtual const char* what() const throw() {
                    return s.c_str();
                }
        };
        class FormAlreadySignedException : public std::exception {
            Bureaucrat &b;
            Form &f;
            std::string s;
            public:
                FormAlreadySignedException();
                ~FormAlreadySignedException() throw();
                FormAlreadySignedException(Bureaucrat &b, Form &f);
                virtual const char* what() const throw() {
                    return s.c_str();
                }
        }; */
};

std::ostream &operator<<(std::ostream &out, const AForm &rhs);
