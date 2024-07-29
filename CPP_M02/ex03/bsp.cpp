/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:01:59 by rluari            #+#    #+#             */
/*   Updated: 2024/04/06 17:00:18 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

Fixed ft_sign(Point p1, Point p2, Point p3) 
{
    return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())) - ((p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
    //if the return value is negative, the point is on the right side of the vector, if it is positive, it is on the left side
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool has_neg, has_pos;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "point: " << point << std::endl;
    
    Fixed x ( ft_sign(point, a, b) ); 
    Fixed y ( ft_sign(point, b, c) ); 
    Fixed z ( ft_sign(point, c, a) ); 

    has_neg = (x < 0) || (y < 0) || (z < 0); //at least one of (x, y, z) should be negative, but not all of them, that's when the point is outside the triangle
    has_pos = (x > 0) || (y > 0) || (z > 0);

    return !(has_neg && has_pos);
}
