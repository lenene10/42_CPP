/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:31:05 by rluari            #+#    #+#             */
/*   Updated: 2024/03/28 14:09:14 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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
		

		//Others
		int getRawBits(void) const;	//the ending const means that the object and it's members are not modifiable
		void setRawBits(int const raw);
		float toFloat(void) const;	//converts the fixed point value to a floating point value
		int	toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif