/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:12:52 by rluari            #+#    #+#             */
/*   Updated: 2024/04/24 18:59:01 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(std::string input);
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &src);
        /* char    _char_val;
        int     _int_val;
        float   _float_val;
        double  _double_val;

        bool    _impossible;
        input_type _actual_type;

        std::string _input; */
    public:
        static void convert(std::string input);
        class UnableToConvert : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class OutOfRange : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
