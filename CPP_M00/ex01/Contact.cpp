/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:07:02 by rluari            #+#    #+#             */
/*   Updated: 2024/02/24 13:34:49 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

Contact::~Contact()
{}

Contact& Contact::operator=(const Contact& other)
{
	first_name = other.first_name;
	last_name = other.last_name;
	nickname = other.nickname;
	phone_number = other.phone_number;
	darkest_secret = other.darkest_secret;
	return (*this);
}

Contact::Contact(const Contact& other)
{
	(void)other;
}

void	Contact::setContact()
{
	std::cout << "Enter first name: \n";
	std::cin >> this->first_name;
	std::cout << "Enter last name: \n";
	std::cin >> this->last_name;
	std::cout << "Enter nickname: \n";
	std::cin >> this->nickname;
	std::cout << "Enter phone number: \n";
	std::cin >> this->phone_number;
	std::cout << "Enter darkest secret: \n";
	std::cin >> this->darkest_secret;
}

void	Contact::printExtendedContact()
{
	std::cout << "_______________________________" << std::endl;
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
	std::cout << "_______________________________" << std::endl;
}

void	print_spaces(int n)
{
	for (int i = 0; i < n; i++)
		std::cout << " ";
}

void	print_short_name(std::string name)
{
	std::cout << name.substr(0, 9) << ".|";
}

void	Contact::printContactInline()
{
	if (this->first_name.length() > 10)
		print_short_name(this->first_name);
	else
	{
		print_spaces(10 - this->first_name.size());
		std::cout << this->first_name << "|";
	}
	
	if (this->last_name.length() > 10)
		print_short_name(this->last_name);
	else
	{
		print_spaces(10 - this->last_name.size());
		std::cout << this->last_name << "|";
	}

	if (this->nickname.length() > 10)
		print_short_name(this->nickname);
	else
	{
		print_spaces(10 - this->nickname.size());
		std::cout << this->nickname << "|";
	}
	
	//std::cout << std::endl;
}