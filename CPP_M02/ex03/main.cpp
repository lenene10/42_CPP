/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:13:15 by rluari            #+#    #+#             */
/*   Updated: 2024/04/06 16:55:39 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void )
{
    Point a(0.0f, 0.0f);
    Point b(0.0f, 5.0f);
    Point c(5.0f, 0.0f);

    Point random_point(6.5f, 0.5f);

    bool res = bsp(a, b, c, random_point);
    
    std::cout << random_point << " is " << (res ? "inside" : "outside") << " the triangle" << std::endl;

    return 0;
}
