/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:55:54 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 16:51:25 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout<< "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout<< "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
        this->type = copy.getType();
    return (*this);
}

void Dog::makeSound() const
{
    std::cout<< "Woof" << std::endl;
}

