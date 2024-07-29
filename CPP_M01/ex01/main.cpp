/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:25:06 by rluari            #+#    #+#             */
/*   Updated: 2024/03/08 14:53:49 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	Zombie *horde = zombieHorde(3, "Zombie");
	for (int i = 0; i < 3; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}