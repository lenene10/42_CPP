/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:25:06 by rluari            #+#    #+#             */
/*   Updated: 2024/02/03 14:56:03 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string str_var = "HI THIS IS BRAIN";
    std::string *stringPTR = &str_var;
    std::string &stringREF = str_var;

    std::cout << "Address of the string: " << &str_var << "\n";
    std::cout << "Address of the string using pointer: " << stringPTR << "\n";
    std::cout << "Address of the string using reference: " << &stringREF << "\n";

    std::cout << "Value of str_var: " << str_var << "\n";
    std::cout << "Value of str_var using pointer: " << *stringPTR << "\n";
    std::cout << "Value of str_var using reference: " << stringREF << "\n";
    return 0;
}