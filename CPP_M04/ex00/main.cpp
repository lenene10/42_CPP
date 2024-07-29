/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluari <rluari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:25:49 by rluari            #+#    #+#             */
/*   Updated: 2024/04/08 16:41:00 by rluari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        std::cout << "\n---Constructors---\n" <<std::endl;
        
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* c = new Cat();
        const Cat* i = new Cat();

        std::cout << "\n---Testing---\n" <<std::endl;
        
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        c->makeSound();
        meta->makeSound();
        
        std::cout << "\n---Destructors---\n" <<std::endl;
        
        delete meta;
        delete j;
        delete i;
        delete c;
    }
    {
        std::cout << "\n---WRONG ANIMALS---\n---Constructors---\n" <<std::endl;
        
        const WrongAnimal* meta2 = new WrongAnimal();
        const WrongCat *k = new WrongCat();
        const WrongAnimal* j2 = new WrongDog();
        const WrongAnimal* i2 = new WrongCat();

        std::cout << "\n---Testing---\n" <<std::endl;

        std::cout << j2->getType() << " " << std::endl;
        std::cout << i2->getType() << " " << std::endl;
        i2->makeSound(); //will output the Animal sound!
        j2->makeSound();
        meta2->makeSound();
        k->makeSound();

        std::cout << "\n---Destructors---\n" <<std::endl;

        delete meta2;
        delete j2;
        delete i2;
        delete k;
    }
    
    return 0;
}