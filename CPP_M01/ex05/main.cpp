/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:40:59 by rluari            #+#    #+#             */
/*   Updated: 2024/03/04 15:35:17 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]\n";
		return (1);
	}	
	Harl harl;
	harl.complain(argv[1]);
	return (0);
}