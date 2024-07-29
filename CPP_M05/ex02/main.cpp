/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:40:53 by rluari            #+#    #+#             */
/*   Updated: 2024/04/12 12:16:08 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <exception>
#include <iostream>

int main()
{
    Bureaucrat b("Jürgen");
    b.setGrade(140);
    AForm *theform = new ShrubberyCreationForm("asdtarget");

    std::cout << "\n--- TESTIG ---\n" << std::endl;
    std::cout << "--- Form not signed example ---\n" << std::endl;

    try {
        theform->execute(b);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    b.signForm(*theform);
    
    std::cout << "\n--- Form signed but too low grade to execute example: ---\n" << std::endl;
    try {
        theform->execute(b);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    b.setGrade(120);
    
    std::cout << "\n--- Successfully executing Shruberry Creation Form: ---\n" << std::endl;
    try {
        theform->execute(b);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- Testing RobotomyRequestForm: ---\n" << std::endl;
    AForm *theform2 = new RobotomyRequestForm("robotarget");
    b.setGrade(44);
    theform2->beSigned(b);
    try {
        theform2->execute(b);
        theform2->execute(b);
        theform2->execute(b);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- Testing PresidentialPardonForm: ---\n" << std::endl;
    AForm *theform3 = new PresidentialPardonForm("pardontarget");
    b.setGrade(5);
    b.decrementGrade();
    theform3->beSigned(b);
    //grade will be to low to execute
    try {
        theform3->execute(b);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    //now grade is ok now
    b.incrementGrade();
    b.executeForm(*theform3);

    std::cout << "\n--- DESTRUCTORS ---\n" << std::endl;

    delete theform;
    delete theform2;
    delete theform3;
    return 0;
}