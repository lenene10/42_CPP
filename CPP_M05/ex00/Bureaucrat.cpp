/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:28:57 by rluari            #+#    #+#             */
/*   Updated: 2024/04/22 16:55:12 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iterator>
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat() : Name("default name"), Grade(150)
{
    std::cout << "Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : Name("default name"), Grade(grade)
{
    this->setGrade(grade);
    std::cout << "Bureaucrat created with " << grade << " grade." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name) : Name(name), Grade(150)
{
    std::cout << "Bureaucrat " << name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string const &name) : Name(name), Grade(grade)
{
    this->setGrade(grade);
    std::cout << "Bureaucrat " << name << " created with " << grade << " grade." << std::endl;
}



Bureaucrat::Bureaucrat(Bureaucrat const &src) : Name(src.Name), Grade(src.Grade)
{
    std::cout << "Bureaucrat " << Name << " created by copy constr" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << Name << " destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    Grade = rhs.Grade;
    static_cast<std::string>(this->Name) = rhs.getName();
    std::cout << "Bureaucrat " << Name << " assigned" << std::endl;
    return *this;
}

// --------------------

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "OMG! Grade is too low! It is now set to 150.";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "OMG! Grade is too high! It it now set to 1.";
}

// --------------------

const std::string Bureaucrat::getName() const
{
    return this->Name;
}

int Bureaucrat::getGrade() const
{
    return this->Grade;
}

void    Bureaucrat::incrementGrade()
{
    if (this->Grade == 1)
        throw  GradeTooHighException();
    else
        this->Grade--;  //increment means 3 becomes 2
}

void    Bureaucrat::decrementGrade()
{
    if (this->Grade == 150)
        throw  GradeTooLowException();
    else
        this->Grade++;  //decrement means 149 becomes 150
}

void    Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
    {
        this->Grade = 1;
        throw  GradeTooHighException();
    }
    else if (grade > 150)
    {
        this->Grade = 150;
        throw  GradeTooLowException();
    }
    else
        this->Grade = grade;
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (out);
}
