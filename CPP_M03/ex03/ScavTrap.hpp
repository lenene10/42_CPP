/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:34:40 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 12:44:23 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    bool guardingGate;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& src);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& otherScavTrap);

        void attack(const std::string& target);
        void guardGate();
        
        static const unsigned int energy_points = 50;
};

#endif