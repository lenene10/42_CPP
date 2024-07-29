/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:47:11 by rluari            #+#    #+#             */
/*   Updated: 2024/04/07 12:27:08 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    {
		std::cout << "----Constructing----" << std::endl;
		ClapTrap a;
		ClapTrap b("Cody");

		std::cout << "----Testing----" << std::endl;
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
		std::cout << "----Deconstructing----" << std::endl;
	}
	{
		std::cout << "----Constructing----" << std::endl;
		ScavTrap c;
		ScavTrap d("Savage");

		std::cout << "----Testing----" << std::endl;
		c.attack("CloneTrap");
		// for (int i = 0; i < 50; i++)
		// 	c.attack("CloneTrap");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Savage-clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.takeDamage(35);
		d.beRepaired(10);
		d.attack("ScavTrap-clone");
		std::cout << "----Deconstructing----" << std::endl;
	}

    return (0);
}