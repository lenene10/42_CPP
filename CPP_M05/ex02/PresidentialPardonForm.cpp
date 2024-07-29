/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:03:10 by rluari            #+#    #+#             */
/*   Updated: 2024/04/11 17:39:01 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("DefaultTarget")
{
    std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = target;
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    this->_target = other._target;
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)        
{
	std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
    this->_target = rhs._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

//getter

std::string PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

//method

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if ((int)executor.getGrade() > this->getMinGradeToExecute())
    {
		std::cout << "Couldn't execute, because: ";
		throw (AForm::GradeTooLowException());
    }
	else if (this->getSigned() == false)
    {
		std::cout << "Couldn't execute, because: ";
		throw (AForm::FormNotSignedException());
    }
	else
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
