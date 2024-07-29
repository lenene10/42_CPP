/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:25:49 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 17:53:23 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n---Constructors---\n" <<std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    //const Animal* meta = new Animal();

    std::cout << "\n---Testing---\n" <<std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    //meta->makeSound();
    
    std::cout << "\n---Destructors---\n" <<std::endl;

    delete i;
    delete j;
    
    return 0;
}