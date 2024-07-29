/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:25:17 by rluari            #+#    #+#             */
/*   Updated: 2024/02/04 18:30:28 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie() {
	std::cout << "Zombie has been created\n";
}

//Constructor with name
Zombie::Zombie(std::string name)  {
	this->name = name;
	std::cout << "Zombie " << name << " has been created\n";
}

// Name setter
void Zombie::setName(std::string name) {
	this->name = name;
}

// Name copier operator
Zombie& Zombie::operator=(const Zombie& zombie) {
	name = zombie.name;
	return *this;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

std::string Zombie::getName() const {
	return name;
}
Zombie::~Zombie() {
	std::cout << "Zombie " << name << " has been destroyed\n";
}
