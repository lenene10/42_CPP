/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:27:00 by rluari            #+#    #+#             */
/*   Updated: 2024/04/10 21:45:59 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form{
    bool                _signed;
    const std::string   _formname;
    const int           _min_grade_to_sign;
    const int           _min_grade_to_execute;
    public:
        Form();
        Form(std::string name, int min_sign, int min_exec);
        Form(const Form& other);
        Form &operator=(const Form& other);
        ~Form();
        
        const std::string getName() const;
        bool getSigned() const;
        int getMinGradeToSign() const;
        int getMinGradeToExecute() const;


        void    beSigned(Bureaucrat &b);

        class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
        };

         class GradeTooHighException : public std::exception {
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

std::ostream &operator<<(std::ostream &out, const Form &rhs);
