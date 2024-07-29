/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:38:35 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 12:44:27 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    // name is DefaultName because it is already assigned in ClapTrap()
    (*this).hitPoints = 100;
    (*this).energyPoints = 50;
    (*this).attackDamage = 20;
    (*this).guardingGate = false;

    std::cout << "ScavTrap " << (*this).Name << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    // we dont assign name to scavtrap because it is already done in ClapTrap(name), so we just need to assign the other attributes
    (*this).hitPoints = 100;
    (*this).energyPoints = 50;
    (*this).attackDamage = 20;
    (*this).guardingGate = false;
    std::cout << "ScavTrap " << (*this).Name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    *this = src;
    std::cout << "Copy constructor of" << (*this).Name << "called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << (*this).Name << " destroyed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &otherST)
{
    if (this != &otherST)
    {
        static_cast<ClapTrap &>(*this) = otherST;
        (*this).guardingGate = otherST.guardingGate;
    }
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if ((*this).energyPoints > 0 && (*this).hitPoints > 0)
    {
        (*this).energyPoints -= 1;
        std::cout << "SCAVtrap " << (*this).Name << " attack " << target << ", causing " << (*this).attackDamage << " points of damage!" << std::endl;
        //target is just a string, so we can't do target.hitPoints -= (*this).attackDamage;
    }
    else if ((*this).energyPoints <= 0)
        std::cout << "SCAVtrap " << (*this).Name << " has no energy points to attack!" << std::endl;
    else if ((*this).hitPoints <= 0)
        std::cout << "SCAVtrap " << (*this).Name << " cannot attack because he is dead!" << std::endl;
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
