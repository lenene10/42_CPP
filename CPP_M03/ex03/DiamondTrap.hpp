/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:54:38 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 12:44:49 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap    //last one that has in the header redefined the attack() "wins", since both have, i must chose, using "using"
{
    std::string Name;
    public:
        DiamondTrap();
        DiamondTrap(std::string Name);
        DiamondTrap(const DiamondTrap& src);
        ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap& otherDiamondTrap);

        using ScavTrap::attack;
        void whoAmI();
};