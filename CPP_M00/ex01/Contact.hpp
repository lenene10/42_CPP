/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:06:59 by rluari            #+#    #+#             */
/*   Updated: 2024/02/22 12:52:19 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string	phone_number;
	std::string darkest_secret;
	public:
		Contact();
		~Contact();
		Contact& operator=(const Contact& other);
		Contact(const Contact& other);
		void	setContact();
		void	printContactInline();
		void 	printExtendedContact();

};

#endif