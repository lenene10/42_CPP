/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:40:53 by rluari            #+#    #+#             */
/*   Updated: 2024/04/22 16:44:52 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <ostream>

int main()
{
    Bureaucrat b("Jürgen");
    b.setGrade(60);
    std::cout << "\n--- Constructing form with wrong grade ---\n" << std::endl;
    try {
        Form f("BadForm", 400, 300);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "\n--- Constructing with good grade but bure cannot sign ---\n" << std::endl;
    try {
        Form good_form("GoodForm", 50, 10);
        std::cout << good_form << std::endl;
        b.signForm(good_form);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- Constructing with good grade and bure can sign ---\n" << std::endl;

    try {
        Form good_form("GoodForm", 70, 10);
        b.signForm(good_form);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    
    return 0;
}