/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:25:06 by rluari            #+#    #+#             */
/*   Updated: 2024/03/08 20:47:50 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name );

Zombie* newZombie( std::string name );

int main()
{
	try{
		Zombie *x = newZombie("Johnn");
		Zombie *y = x;
		randomChump("Bobby");
		x->announce();
		y->announce();
		x->~Zombie();
		y->~Zombie();
		delete x;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}