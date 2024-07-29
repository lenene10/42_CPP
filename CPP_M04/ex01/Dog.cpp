/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:55:54 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 17:48:00 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->brain = new Brain();
    this->type = "Dog";
    std::cout<< "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout<< "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    this->brain = NULL;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
        this->type = copy.getType();
    if (this->brain != NULL)
        delete this->brain;
    this->brain = new Brain(*(copy.brain));
    return (*this);
}

void Dog::makeSound() const
{
    std::cout<< "Woof" << std::endl;
}

