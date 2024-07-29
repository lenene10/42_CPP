/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:32:29 by rluari            #+#    #+#             */
/*   Updated: 2024/04/22 16:42:45 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("DefaultTarget")
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    this->_target = other._target;
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)        
{
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
    this->_target = rhs._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

static int success_var = 1;

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
	else if (success_var > 0)
    {
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
        success_var *= -1;
    }
	else
		std::cout << "Robotomy failed" << std::endl;
}
