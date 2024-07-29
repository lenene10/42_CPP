/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:27:04 by rluari            #+#    #+#             */
/*   Updated: 2024/04/10 21:45:11 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _signed(false), _formname("DefaultForm"), _min_grade_to_sign(120), _min_grade_to_execute(20)
{
    std::cout << "Default Form constructor." << std::endl;
}

Form::Form(std::string name, int min_sign, int min_exec) : _signed(false), _formname(name), _min_grade_to_sign(min_sign), _min_grade_to_execute(min_exec)
{
    if (_min_grade_to_sign > 150)
    {
        std::cout << "Cannot construct because ";
        throw Form::GradeTooLowException();
    }
    else if (_min_grade_to_sign < 1)
    {
        std::cout << "Cannot construct because ";
        throw Form::GradeTooHighException();
    }

    if (_min_grade_to_execute > 150)
    {
        std::cout << "Cannot construct because ";
        throw Form::GradeTooLowException();
    }
    else if (_min_grade_to_execute < 1)
    {
        std::cout << "Cannot construct because ";
        throw Form::GradeTooHighException();
    }
    std::cout << "Form " << _formname << " created" << std::endl;

}
Form::Form(const Form& other) : _signed(other._signed), _formname(other._formname), _min_grade_to_sign(other._min_grade_to_execute), _min_grade_to_execute(other._min_grade_to_execute)
{
        std::cout << "Form " << _formname << " created by copy constructor" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
    std::cout << "Form Assignation operator called" << std::endl;
    //nothing to assign
    _signed = rhs._signed;
    *const_cast<std::string *>(&(this->_formname)) = rhs._formname;
    *const_cast<int *>(&(this->_min_grade_to_execute)) = rhs._min_grade_to_execute;
    *const_cast<int *>(&(this->_min_grade_to_sign)) = rhs._min_grade_to_sign;
    return *this;
}

Form::~Form()
{
    //std::cout << "Form " << _formname << " deleted" << std::endl;
}

//Methods

const std::string Form::getName() const
{
    return this->_formname;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getMinGradeToSign() const
{
    return this->_min_grade_to_sign;
}

int Form::getMinGradeToExecute() const
{
    return this->_min_grade_to_execute;
}

void    Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->_min_grade_to_sign)
    {
        std::cout << b.getName() << " couldn’t sign " << this->getName() << " because: ";
        throw(Form::GradeTooLowException());
    }
    else if (this->getSigned() == true)
        std::cout << b.getName() << " couldn’t sign " << this->getName() << " because: it's already signed." << std::endl;
    else
    {
        this->_signed = true;
        std::cout << b.getName() << " signed " << this->getName() << std::endl;
    }
}


// ostream Overload
std::ostream	&operator<<(std::ostream &out, const Form &rhs)
{
	out << "Form " << rhs.getName() <<
	"\n\tis signed: \t" << rhs.getSigned() <<
	"\n\tsign-grade: \t" << rhs.getMinGradeToSign() <<
	"\n\texec-grade: \t" << rhs.getMinGradeToExecute();
	return (out);
}

//FormSignedException

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return ("grade is too low.");
}

char const	*Form::GradeTooHighException::what(void) const throw()
{
	return ("grade is too high.");
}



/* Form::FormAlreadySignedException::FormAlreadySignedException(Bureaucrat &b, Form &f) : b(b), f(f),
    s(f.getName() + " Form is already signed by " + b.getName() + "\n")
{}

Form::GradeTooLowException::GradeTooLowException(Bureaucrat &b, Form &f) : b(b), f(f), 
    s(b.getName() + " couldn’t sign " + f.getName() + " because " + "the grade of the burocreaut is too low.\n")
{}

Form::FormAlreadySignedException::~FormAlreadySignedException() throw()
{}

Form::GradeTooLowException::~GradeTooLowException() throw()
{} */
