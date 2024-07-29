/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:42:53 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 16:43:19 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
    std::string ideas[100];
    public:
        Brain();
        virtual ~Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
};