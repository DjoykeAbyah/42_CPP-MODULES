/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/16 21:34:56 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/17 20:28:34 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.hpp"
#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include "../header/WrongAnimal.hpp"
#include "../header/WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;
		
		i->makeSound(); //will output the Cat sound
		j->makeSound(); //will output the Dog sound
		meta->makeSound(); //will output The animal sound
		std::cout << std::endl;
		
		delete meta;
		delete i;
		delete j;
		std::cout << std::endl;
	}
	{
		const WrongAnimal* wrongmeta = new WrongAnimal();
		const WrongAnimal* wrongcat = new WrongCat();
		std::cout << std::endl;
		
		std::cout << wrongcat->getType() << " " << std::endl;
		std::cout << std::endl;
		
		wrongcat->makeSound(); //will output the WrongAnimal sound
		wrongmeta->makeSound(); //will output the WrongAnimal sound
		std::cout << std::endl;

		delete wrongmeta;
		delete wrongcat;
	}
	return 0;
}
