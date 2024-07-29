/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:41:19 by rluari            #+#    #+#             */
/*   Updated: 2024/04/06 14:13:53 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(const Point &p)
{
    *this = p;
}

Point::Point(const float x, const float y)
{
    const_cast<Fixed&>(this->x) = Fixed(x);
    const_cast<Fixed&>(this->y) = Fixed(y);
}

Point &Point::operator=(const Point &p)
{
    if (this != &p)
    {
        const_cast<Fixed&>(this->x) = p.getX();
        const_cast<Fixed&>(this->y) = p.getY();
    }
    return *this;
}

Point::~Point()
{}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}

std::ostream &operator<<(std::ostream &out, const Point &p)
{
    out << "Point(" << p.getX() << ", " << p.getY() << ")";
    return out;
}
