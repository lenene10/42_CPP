/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:13:24 by rluari            #+#    #+#             */
/*   Updated: 2024/05/08 13:49:25 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <limits>
#include <string>
#include <cstdlib>
#include <iostream>

int	main(void)
{
	PhoneBook	pb;
	std::string tmp_str;
	std::string input_cmd = "";
	int			index;

	while (1)
	{
		std::cout << "Enter a command: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input_cmd);
		if (input_cmd == "ADD")
		{
			Contact *contact = new Contact();
			contact->setContact();
			pb.add(contact);
			delete contact;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (input_cmd == "SEARCH")
		{
			pb.print_all_contacts();
			std::cout << "_______________________________________________" << std::endl;
			std::cout << "Enter the index of the contact you want to see" << std::endl;
			std::cout << "To return, press '0'" << std::endl;
			std::getline(std::cin, tmp_str);
			index = atoi(tmp_str.c_str());
			pb.search(index);
		}
		else if (input_cmd == "EXIT")
			break ;
	}
	return (0);
}