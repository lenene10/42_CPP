/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:40:59 by rluari            #+#    #+#             */
/*   Updated: 2024/03/04 17:05:32 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int		get_level_num(std::string level)
{
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return (i);
	}
	return (-1);
}

void	ft_get_compl(Harl harl, std::string level)
{
	int level_num = get_level_num(level);
	switch (level_num)
	{
		case 0:
			harl.complain(level_num++);
		case 1:
			harl.complain(level_num++);
		case 2:
			harl.complain(level_num++);
		case 3:
			harl.complain(level_num++);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}	
	Harl harl;
	ft_get_compl(harl, argv[1]);
	return (0);
}