/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:43:34 by rluari            #+#    #+#             */
/*   Updated: 2024/02/04 19:18:55 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

const std::string &Weapon::getType() const
{
    return (this->type);
}

Weapon &Weapon::operator=(Weapon &type)
{
    this->type = type.getType();
    return *this;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << this->type << " destroyed" << std::endl;
}