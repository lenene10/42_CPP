/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:40:53 by rluari            #+#    #+#             */
/*   Updated: 2024/04/12 11:59:56 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <exception>
#include <iostream>

int main()
{
    Bureaucrat *clara = new Bureaucrat("Clara");
    Intern  *little_guy = new Intern();

    AForm *scf_form1 = little_guy->makeForm("ShrubberyCreationForm", "Bender");

    try{
        clara->signForm(*scf_form1);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    clara->setGrade(140);
    clara->signForm(*scf_form1);
    
    try
    {
        scf_form1->execute(*clara);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    clara->setGrade(130);
    scf_form1->execute(*clara);
    std::cout << *scf_form1 << std::endl;

    AForm *wrong_form;
    try {
        wrong_form = little_guy->makeForm("asdasdasd", "Bender");
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    delete clara;
    delete little_guy;
    delete scf_form1;
    
    return 0;
}