/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:47:11 by rluari            #+#    #+#             */
/*   Updated: 2024/04/07 15:03:24 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "---Constructors---" <<std::endl;

	FragTrap fragtrap("FragtrapClement");
	FragTrap fragtrap2;
	std::cout << "---Testing---" <<std::endl;

	fragtrap.attack("Clement");
	fragtrap.takeDamage(10);
	fragtrap.beRepaired(10);
	FragTrap fragtrap3(fragtrap);
	fragtrap3.takeDamage(10);
	fragtrap.highFivesGuys();
	
	std::cout << "---Destructors---" <<std::endl;
    return (0);
}