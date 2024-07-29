/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:44:47 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 15:46:15 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout<< "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout<< "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout<< "Wrong Meow" << std::endl;
}