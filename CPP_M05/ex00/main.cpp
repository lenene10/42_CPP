/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:40:53 by rluari            #+#    #+#             */
/*   Updated: 2024/04/22 16:44:37 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b("Jürgen");
    std::cout << b << std::endl;
    std::cout << b << std::endl;
    try
    {
        b.setGrade(1);
        b.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        Bureaucrat c(151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}