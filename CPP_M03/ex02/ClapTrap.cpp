/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:31:51 by rluari            #+#    #+#             */
/*   Updated: 2024/04/07 15:03:07 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    (*this).Name = "DefaultName";
    (*this).hitPoints = 10;
    (*this).energyPoints = 10;
    (*this).attackDamage = 0;
    std::cout << "ClapTrap " << (*this).Name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    (*this).Name = name;
    (*this).hitPoints = 10;
    (*this).energyPoints = 10;
    (*this).attackDamage = 0;
    std::cout << "ClapTrap " << (*this).Name << " created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    (*this).Name = src.Name;
    (*this).hitPoints = src.hitPoints;
    (*this).energyPoints = src.energyPoints;
    (*this).attackDamage = src.attackDamage;
    std::cout << "Copy constructor of" << (*this).Name << "called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& otherClapTrap)
{
    if (this != &otherClapTrap) //Example: a = a, then dont do anything
    {
        (*this).Name = otherClapTrap.Name;
        (*this).hitPoints = otherClapTrap.hitPoints;
        (*this).energyPoints = otherClapTrap.energyPoints;
        (*this).attackDamage = otherClapTrap.attackDamage;
    }
    std::cout << "Assignment operator of " << (*this).Name << " called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << (*this).Name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if ((*this).energyPoints > 0 && (*this).hitPoints > 0)
    {
        (*this).energyPoints -= 1;
        std::cout << "ClapTrap " << (*this).Name << " attack " << target << ", causing " << (*this).attackDamage << " points of damage!" << std::endl;
        //target is just a string, so we can't do target.hitPoints -= (*this).attackDamage;
    }
    else if ((*this).energyPoints <= 0)
        std::cout << "ClapTrap " << (*this).Name << " has no energy points to attack!" << std::endl;
    else if ((*this).hitPoints <= 0)
        std::cout << "ClapTrap " << (*this).Name << " cannot attack because he is dead!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    int difference = (*this).hitPoints - amount;
    
    if ((*this).hitPoints > 0)
    {
        if (difference <= 0)
        {
            (*this).hitPoints = 0;
            std::cout << "ClapTrap " << (*this).Name << " died!" << std::endl;
        }
        else
        {
            std::cout << "ClapTrap " << (*this).Name << " takes " << amount << " points of damage!" << std::endl;
            (*this).hitPoints -= amount;
        }
    }
    else 
        std::cout << "ClapTrap " << (*this).Name << " is already dead, leave him alone!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if ((*this).energyPoints > 0 && (*this).hitPoints > 0)
    {
        (*this).energyPoints -= 1;
        std::cout << "ClapTrap " << (*this).Name << " repaired by " << amount << " points!" << std::endl;
        (*this).hitPoints += amount;
    }
    else if ((*this).energyPoints == 0)
        std::cout << "ClapTrap " << (*this).Name << " has no energy points to be repaired!" << std::endl;
    else
        std::cout << "ClapTrap " << (*this).Name << " is dead, cannot be repaired anymore" << std::endl;
}

//as you can see, you cannot gain energypoints

std::string ClapTrap::getName(void) const
{
    return (*this).Name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
    return (*this).hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return (*this).energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return (*this).attackDamage;
}

