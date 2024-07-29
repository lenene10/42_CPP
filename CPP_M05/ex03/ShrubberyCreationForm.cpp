/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:36:00 by rluari            #+#    #+#             */
/*   Updated: 2024/04/22 16:42:48 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = "default";
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = target;
    std::cout << "ShrubberyCreationForm Parametric constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)        
{
    
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
    this->_target = rhs._target;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    this->_target = other._target;
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

//getters

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

//methods

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
	{
		std::cout << "Executing ShrubberyCreationForm..." << std::endl;
        std::string filename = this->getTarget().append("_shrubbery");
        std::ofstream outfile(filename.c_str());
		for (int i = 0; i < 3; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		    std::endl;
		}
		outfile.close();
		std::cout << "Done!" << std::endl;

	}
}
