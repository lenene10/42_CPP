/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:47:32 by rluari            #+#    #+#             */
/*   Updated: 2024/04/24 18:13:16 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

typedef struct s_Data
{
    std::string s1;
    int n;
    std::string s2;
} Data;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &src);
        ~Serializer();
        Serializer &operator=(const Serializer &src);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);};