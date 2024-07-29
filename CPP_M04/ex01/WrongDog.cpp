/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:44:57 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 16:28:24 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
    this->type = "WrongDog";
    std::cout<< "WrongDog constructor called" << std::endl;
}

WrongDog::~WrongDog()
{
    std::cout<< "WrongDog destructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &copy)
{
    *this = copy;
}

WrongDog &WrongDog::operator=(const WrongDog &copy)
{
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

void WrongDog::makeSound() const
{
    std::cout<< "Wrong Woof" << std::endl;
}