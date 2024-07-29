/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:41:48 by rluari            #+#    #+#             */
/*   Updated: 2024/03/04 17:04:33 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
    public:
        Harl();
        ~Harl();
		Harl& operator=(const Harl& harl);
        void complain( int level );
};

#endif