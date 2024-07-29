/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:38:22 by rluari            #+#    #+#             */
/*   Updated: 2024/04/06 12:35:25 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fraction = 8;


//Constructors

Fixed::Fixed() : fixed_value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value)
{
	fixed_value = int_value * pow(2, fraction);
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_value)
{
	/* std::cout << (float_value * pow(2, fraction)) << std::endl;
	fixed_value = (float_value * pow(2, fraction)); */
	fixed_value = roundf(float_value * pow(2, fraction));	//the result of this operation is 64 bits (its a double), but 
													//floats are 32 bits, so that is why we need to cast and at the same time also round it to the nearest integer
	//without roundf, a result of for example 	10859.5 would be stored in the fixed_value as 10859 instead of 10860
	//std::cout << (*this).toFloat() << std::endl;
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

// Assignment operator

Fixed &Fixed::operator=(const Fixed &f)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	fixed_value = f.getRawBits();
	return *this;
}

// Output operator

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return out;
}

// Member functions
float	Fixed::toFloat() const
{
	return ((fixed_value) / pow(2, fraction));
}

int	Fixed::toInt() const
{
	return roundf(fixed_value / pow(2, fraction));
}

int Fixed::getRawBits() const
{
	return fixed_value;
}

void Fixed::setRawBits(int const raw)
{
	fixed_value = raw;
}


// Comparison operators

bool Fixed::operator>(const Fixed &f) const
{
	return fixed_value > f.getRawBits();
}

bool Fixed::operator<(const Fixed &f) const
{
	return fixed_value < f.getRawBits();
}

bool Fixed::operator>=(const Fixed &f) const
{
	return fixed_value >= f.getRawBits();
}

bool Fixed::operator<=(const Fixed &f) const
{
	return fixed_value <= f.getRawBits();
}

bool Fixed::operator==(const Fixed &f) const
{
	return fixed_value == f.getRawBits();
}

bool Fixed::operator!=(const Fixed &f) const
{
	return fixed_value != f.getRawBits();
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed &f) const
{
	return Fixed(toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed &f) const
{
	return Fixed(toFloat() - f.toFloat());
}

Fixed Fixed::operator*(const Fixed &f) const
{
	return Fixed(toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f) const
{
	if (f.toFloat() == 0)
	{
		std::cout << "Error: division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed((*this).toFloat() / f.toFloat());
}

// Increment and decrement operators

Fixed &Fixed::operator++()	//pre incrementation
{
	fixed_value++;
	return *this;
}

Fixed Fixed::operator++(int)	//post incrementation, returns the copy of tmp. Int is there to differentiate between the two
{
	Fixed tmp(*this);
	(*this).operator++();
	return tmp;					//return the object
}

Fixed &Fixed::operator--()
{
	fixed_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// Min and max functions

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}