/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:25:20 by rluari            #+#    #+#             */
/*   Updated: 2024/02/03 14:53:12 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();	//Constructor with no arguments
		Zombie(std::string zombieName); //Constructor with name
		Zombie(Zombie& zombie); //Copy constructor
		Zombie& operator=(Zombie& zombie); //Assignation operator overload
		void announce();		
		std::string getName() const;
		~Zombie();
};


#endif
