/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:47:11 by rluari            #+#    #+#             */
/*   Updated: 2024/03/28 16:14:51 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("FragTrap");
    ClapTrap clapTrap2(clapTrap);
    ClapTrap clapTrap3("anotherFragTrap");

    clapTrap = clapTrap3;
    clapTrap.attack("target");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    std::cout << clapTrap.getEnergyPoints() << std::endl;
    std::cout << clapTrap2.getEnergyPoints() << std::endl;
    return (0);
}