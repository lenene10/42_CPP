/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:32:52 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 17:51:13 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal(); //allowing polymorphic behavior
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);

        std::string getType() const;
        virtual void makeSound() const = 0;
};
