/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:06:55 by rluari            #+#    #+#             */
/*   Updated: 2024/02/24 13:36:05 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->last_index = 0;
	this->contact_count = 0;
}

PhoneBook::~PhoneBook()
{}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
	(void)other;
	return (*this);
}

PhoneBook::PhoneBook(const PhoneBook& other)
{
	(void)other;
}

void PhoneBook::add(Contact *contact)
{
	for (int i = 0; i < 8; i++)
	{
		if (i == this->last_index)
		{
			this->contacts[i] = *contact;
			this->last_index++;
			if (this->contact_count < 8)
				this->contact_count++;
			if (last_index == 8)
				last_index = 0;
			break;
		}
	}
}

void	PhoneBook::print_all_contacts()
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << "         " << i + 1 << "|";
		contacts[i].printContactInline();
		std::cout << std::endl;
	}
}

void PhoneBook::search(int index)
{
	if (index == 0)
		return ;
	if (index < 1 || index > 8)
	{
		if (index == 0)
			return ;
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	else if (index > contact_count)
	{
		std::cout << "No contact at this index" << std::endl;
		return ;
	}
	contacts[index - 1].printExtendedContact();
}