/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:40:51 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 17:39:53 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    Brain *brain;
    public:
        Cat();
        ~Cat(); //polymorphic behavior
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);

        void makeSound() const;
};