/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:56:29 by rluari            #+#    #+#             */
/*   Updated: 2024/04/24 17:59:48 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}


//canonical form methods

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer &src) {
    (void)src;
}

Serializer::~Serializer() {

}

Serializer &Serializer::operator=(const Serializer &src) {
    (void)src;
    return (*this);
}
