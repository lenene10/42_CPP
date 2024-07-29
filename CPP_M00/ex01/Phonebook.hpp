/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:06:57 by rluari            #+#    #+#             */
/*   Updated: 2024/02/22 14:37:46 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	Contact contacts[8];
	int		last_index;
	int		contact_count;
	public:
		PhoneBook();
		~PhoneBook();
		PhoneBook& operator=(const PhoneBook& other);
		PhoneBook(const PhoneBook& other);
		void add(Contact *contact);
		void search(int index);
		void print_all_contacts();
};

#endif