/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:17:20 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 12:37:34 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->Name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energy_points;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->Name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src.Name + "_clap_name"), ScavTrap(src.Name), FragTrap(src.Name)
{
    *this = src;
    std::cout << "DiamondTrap " << this->Name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->Name << " destroyed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& otherDiamondTrap)
{
    this->Name = otherDiamondTrap.Name;
    this->hitPoints = otherDiamondTrap.hitPoints;
    this->energyPoints = otherDiamondTrap.energyPoints;
    this->attackDamage = otherDiamondTrap.attackDamage;
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->Name << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}

