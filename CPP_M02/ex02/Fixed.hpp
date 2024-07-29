/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:31:05 by rluari            #+#    #+#             */
/*   Updated: 2024/04/05 13:06:17 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	int fixed_value;
	static const int fraction;
	public:
		//Constructors (incl copy constr)
		Fixed();
		Fixed(const int int_value);
		Fixed(const float float_value);
		Fixed(const Fixed &f);
		
		//Destructor
		~Fixed();

		//Assignment operators
		Fixed &operator=(const Fixed &f);

		//Comparison operators
		bool operator>(const Fixed &f) const;
		bool operator<(const Fixed &f) const;
		bool operator>=(const Fixed &f) const;
		bool operator<=(const Fixed &f) const;
		bool operator==(const Fixed &f) const;
		bool operator!=(const Fixed &f) const;

		//Arithmetic operators

		Fixed operator+(const Fixed &f) const;
		Fixed operator-(const Fixed &f) const;
		Fixed operator*(const Fixed &f) const;
		Fixed operator/(const Fixed &f) const;

		//Increment and decrement operators

		Fixed &operator++();
		Fixed operator++(int);	//(int) is here to distinguish between pre and post incrementation func name, otherwise it will think they are the same
								//also the return is not a reference, because 
		Fixed &operator--();
		Fixed operator--(int);

		//Others
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int	toInt(void) const;
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

