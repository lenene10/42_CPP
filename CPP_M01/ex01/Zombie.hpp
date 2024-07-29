/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:25:20 by rluari            #+#    #+#             */
/*   Updated: 2024/03/04 14:58:34 by rluari           ###   ########.fr       */
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
		Zombie();
		Zombie(std::string name);
		Zombie(Zombie& zombie);
		Zombie& operator=(const Zombie& zombie);
		void setName(std::string name);
		void announce();
		std::string getName() const;
		
		Zombie* zombieHorde( int N, std::string name );
		~Zombie();
};


#endif
