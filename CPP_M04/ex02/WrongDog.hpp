/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:28:44 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 14:13:39 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
    public:
        WrongDog();
        virtual ~WrongDog();
        WrongDog(const WrongDog &copy);
        WrongDog &operator=(const WrongDog &copy);

        void makeSound() const;
};