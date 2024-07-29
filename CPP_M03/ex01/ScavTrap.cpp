/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:38:35 by rluari            #+#    #+#             */
/*   Updated: 2024/04/07 20:52:08 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    //name is DefaultName because it is already assigned in ClapTrap()
    (*this).hitPoints = 100;
    (*this).energyPoints = 50;
    (*this).attackDamage = 20;
    (*this).guardingGate = false;

    std::cout << "ScavTrap " << (*this).Name << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    //we dont assign name to scavtrap because it is already done in ClapTrap(name), so we just need to assign the other attributes
    (*this).hitPoints = 100;
    (*this).energyPoints = 50;
    (*this).attackDamage = 20;
    (*this).guardingGate = false;
    std::cout << "ScavTrap " << (*this).Name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
    *this = src;
    std::cout << "Copy constructor of" << (*this).Name << " S.T. called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << (*this).Name << " destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &otherST)
{
    if (this != &otherST)
    {
        (*this).hitPoints = otherST.hitPoints;
        (*this).energyPoints = otherST.energyPoints;
        (*this).attackDamage = otherST.attackDamage;

        (*this).guardingGate = otherST.guardingGate;
    }
    return (*this);
}

void ScavTrap::guardGate()
{
    if ((*this).guardingGate == true)
    {
        std::cout << "ScavTrap " << (*this).Name << " is already in Gate keeper mode" << std::endl;
        return;
    }
    else
    {
        (*this).guardingGate = true;
        std::cout << "ScavTrap " << (*this).Name << " has entered in Gate keeper mode" << std::endl;
    }
}
