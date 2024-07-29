/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:31:05 by rluari            #+#    #+#             */
/*   Updated: 2024/04/06 12:31:28 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int fixed_value;	//Fixed point value!!
		static const int fraction;
};


#endif