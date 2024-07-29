/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:25:49 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 17:50:46 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n---Constructors---\n" <<std::endl;

    Animal *animals[10];
    
    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();
    
    std::cout << "\n---Testing---\n" <<std::endl;

    animals[0]->makeSound();
    animals[5]->makeSound();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete i;
    delete j;
    
    Dog basic;
    {
        Dog tmp = basic;
    }
    
    std::cout << "\n---Destructors---\n" <<std::endl;

    for (int i = 0; i < 10; i++)
        delete animals[i];
    
    
    return 0;
}