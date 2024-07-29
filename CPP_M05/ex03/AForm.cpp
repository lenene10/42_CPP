/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:27:04 by rluari            #+#    #+#             */
/*   Updated: 2024/04/22 16:38:04 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _signed(false), _formname("DefaultForm"), _min_grade_to_sign(120), _min_grade_to_execute(20)
{
    std::cout << "Default Form constructor." << std::endl;
}

AForm::AForm(std::string name, int min_sign, int min_exec) : _signed(false), _formname(name), _min_grade_to_sign(min_sign), _min_grade_to_execute(min_exec)
{
    if (_min_grade_to_sign > 150)
    {
        std::cout << "Cannot construct because ";
        throw AForm::GradeTooLowException();
    }
    else if (_min_grade_to_sign < 1)
    {
        std::cout << "Cannot construct because ";
        throw AForm::GradeTooHighException();
    }

    if (_min_grade_to_execute > 150)
    {
        std::cout << "Cannot construct because ";
        throw AForm::GradeTooLowException();
    }
    else if (_min_grade_to_execute < 1)
    {
        std::cout << "Cannot construct because ";
        throw AForm::GradeTooHighException();
    }
    std::cout << "Form " << _formname << " created" << std::endl;

}
AForm::AForm(const AForm& other) : _signed(other._signed), _formname(other._formname), _min_grade_to_sign(other._min_grade_to_execute), _min_grade_to_execute(other._min_grade_to_execute)
{
    std::cout << "Form " << _formname << " created by copy constructor" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
    std::cout << "Form Assignation operator called" << std::endl;
    //nothing to assign
    _signed = rhs._signed;
    *const_cast<std::string *>(&(this->_formname)) = rhs._formname;
    *const_cast<int *>(&(this->_min_grade_to_execute)) = rhs._min_grade_to_execute;
    *const_cast<int *>(&(this->_min_grade_to_sign)) = rhs._min_grade_to_sign;
    return *this;
}

AForm::~AForm()
{
    //std::cout << "Form " << _formname << " deleted" << std::endl;
}

//Methods

const std::string AForm::getName() const
{
    return this->_formname;
}

bool AForm::getSigned() const
{
    return this->_signed;
}

int AForm::getMinGradeToSign() const
{
    return this->_min_grade_to_sign;
}

int AForm::getMinGradeToExecute() const
{
    return this->_min_grade_to_execute;
}

void    AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->_min_grade_to_sign)
    {
        std::cout << b.getName() << " couldn’t sign " << this->getName() << " because: ";
        throw(AForm::GradeTooLowException());
    }
    else if (this->getSigned() == true)
    {
        std::cout << b.getName() << " couldn’t sign " << this->getName() << " because: " << std::endl;
        throw(AForm::FormAlreadySignedException());
    }
    else
    {
        this->_signed = true;
        std::cout << b.getName() << " signed " << this->getName() << std::endl;
    }
}


// ostream Overload
std::ostream	&operator<<(std::ostream &out, const AForm &rhs)
{
	out << "Form " << rhs.getName() <<
	"\n\tis signed: \t" << rhs.getSigned() <<
	"\n\tsign-grade: \t" << rhs.getMinGradeToSign() <<
	"\n\texec-grade: \t" << rhs.getMinGradeToExecute();
	return (out);
}

//FormSignedException

char const	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

char const	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");
}

char const	*AForm::FormAlreadySignedException::what(void) const throw()
{
	return ("Form already signed.");
}

char const	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed.");
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
