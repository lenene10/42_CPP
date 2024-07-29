/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:34:36 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 15:55:14 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("UndefinedAnimal")
{
    std::cout<< "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout<< "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
        this->type = copy.getType();
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout<< "Animal sound" << std::endl;
}