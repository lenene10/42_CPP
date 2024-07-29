/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:51:06 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 12:36:10 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("BasicFragTrap")
{
    (*this).hitPoints = 100;
    (*this).energyPoints = 100;
    (*this).attackDamage = 30;

    std::cout << "FragTrap " << (*this).Name << " created" << std::endl;}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    (*this).hitPoints = 100;
    (*this).energyPoints = 100;
    (*this).attackDamage = 30;
    std::cout << "FragTrap " << (*this).Name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
    *this = src;
    std::cout << "Copy constructor of " << (*this).Name << " F.T. called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->Name << " destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& otherFragTrap)
{
    if (this != &otherFragTrap)
    {
        
        static_cast<ClapTrap&>(*this) = otherFragTrap;
        (*this).name = otherFragTrap.name;
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if ((*this).energyPoints > 0 && (*this).hitPoints > 0)
    {
        (*this).energyPoints -= 1;
        std::cout << "FRAGtrap " << (*this).Name << " attack " << target << ", causing " << (*this).attackDamage << " points of damage!" << std::endl;
        //target is just a string, so we can't do target.hitPoints -= (*this).attackDamage;
    }
    else if ((*this).energyPoints <= 0)
        std::cout << "FRAGtrap " << (*this).Name << " has no energy points to attack!" << std::endl;
    else if ((*this).hitPoints <= 0)
        std::cout << "FRAGtrap " << (*this).Name << " cannot attack because he is dead!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << (*this).Name << " requests a high five" << std::endl;
}