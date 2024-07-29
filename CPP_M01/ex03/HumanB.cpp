/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:44:48 by rluari            #+#    #+#             */
/*   Updated: 2024/03/08 20:48:49 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
	if (weapon == NULL)
		std::cout << name << " has no weapon" << std::endl;
	else
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

HumanB::~HumanB()
{}