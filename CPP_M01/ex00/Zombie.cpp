/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:25:17 by rluari            #+#    #+#             */
/*   Updated: 2024/02/03 14:53:56 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string zombieName)
{
	this->name = zombieName;
	std::cout << "Zombie " << name << " has been created\n";
}

// Name copier operator
Zombie& Zombie::operator=(Zombie& zombie) {
	name = zombie.name;
	return *this;
}

void Zombie::announce()
{
	std::cout << "<" << name << "> BraiiiiiiinnnzzzZ...\n";
}

std::string Zombie::getName() const {
	return name;
}
Zombie::~Zombie() {
	std::cout << "Zombie " << name << " has been destroyed\n";
}

