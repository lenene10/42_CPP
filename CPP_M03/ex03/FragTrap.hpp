/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:47:12 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 12:36:20 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& src);
        ~FragTrap();
        FragTrap& operator=(const FragTrap& otherFragTrap);

        void attack(const std::string& target);
        void highFivesGuys(void);
    
    private:
        std::string name;
};