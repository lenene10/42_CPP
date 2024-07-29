/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:03:14 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 12:11:22 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "---Constructors---" <<std::endl;

    DiamondTrap diamondTrap("Johny");
    
	std::cout << "---Testing---" <<std::endl;
    
    diamondTrap.attack("target");
    diamondTrap.takeDamage(10);
    diamondTrap.beRepaired(5);
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    diamondTrap.whoAmI();

	std::cout << "---Destructors---" <<std::endl;

    return 0;
}