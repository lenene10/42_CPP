/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:43:47 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 16:51:30 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout<< "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout<< "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
        this->type = copy.getType();
    return (*this);
}

void Cat::makeSound() const
{
    std::cout<< "Meow" << std::endl;
}