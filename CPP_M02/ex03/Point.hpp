/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:41:41 by rluari            #+#    #+#             */
/*   Updated: 2024/04/06 13:49:03 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
    public:
        Point();
        Point(const Point &p);
        Point(const float x, const float y);
        Point &operator=(const Point &p);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
    private:
        Fixed const x;
        Fixed const y;
};

std::ostream &operator<<(std::ostream &out, const Point &p);
bool bsp( Point const a, Point const b, Point const c, Point const point);