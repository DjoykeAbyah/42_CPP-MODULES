/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/16 21:34:56 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/19 16:05:44 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AAnimal.hpp"
#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include "../header/Brain.hpp"
#include "../header/WrongAnimal.hpp"
#include "../header/WrongCat.hpp"

int main()
{
	{
		std::cout << "\n" << BOLD_TEXT << MAGENTA << "Basic test from subject" << RESET << std::endl;
		
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j;
		delete i;	
	}
	{
		std::cout << "\n" << BOLD_TEXT << MAGENTA << "Parametric constructor test" << RESET << std::endl;

		const AAnimal* fluffy = new Cat("Fluffy");
		const AAnimal* wouwz = new Cat("Wouwz");
		const WrongAnimal* whatsThat = new WrongAnimal("Iewl");
		const WrongCat* puma = new WrongCat("Puma");

		std::cout 	<< "this type: "<< ORANGE << fluffy->getType() << RESET 
					<< "'s name is: " << ORANGE << fluffy->getName() << RESET 
					<< ". And it makes this sound: ";
		fluffy->makeSound();
		std::cout 	<< "this type: "<< ORANGE << wouwz->getType() << RESET 
					<< "'s name is: " << ORANGE << wouwz->getName() << RESET 
					<< ". And it makes this sound: ";
		wouwz->makeSound();
		std::cout 	<< "this type: "<< ORANGE << whatsThat->getType() << RESET 
					<< "'s name is: " << ORANGE << whatsThat->getName() << RESET 
					<< ". And it makes this sound: ";
		whatsThat->makeSound();
		std::cout 	<< "this type: "<< ORANGE << puma->getType() << RESET 
					<< "'s name is: " << ORANGE << puma->getName() << RESET 
					<< ". And it makes this sound: ";
		puma->makeSound();
		std::cout << std::endl;
		
		delete fluffy;
		delete wouwz;
		delete whatsThat;
		delete puma;
	}
	{
		std::cout << "\n" << BOLD_TEXT << MAGENTA << "Copy constructor test" << RESET << std::endl;

		Dog henk("Henk");
		std::cout 	<< "this type: "<< ORANGE << henk.getType() << RESET 
					<< "'s name is: " << ORANGE << henk.getName() << RESET 
					<< ". And it makes this sound: ";
		henk.makeSound();
		
		Dog copyHenk(henk);
			std::cout 	<< "this type: "<< ORANGE << henk.getType() << RESET 
					<< "'s name is: " << ORANGE << henk.getName() << RESET 
					<< ". And it makes this sound: ";
		henk.makeSound();
	}
	{
		std::cout << "\n" << BOLD_TEXT << MAGENTA << "Copy assignment operator test" << RESET << std::endl;

		/**
		 * Object Assignment: 
		 * In this example, we assign the contents of one object to another. 
		 * This invokes the copy assignment operator, which performs a deep copy 
		 * and manages memory correctly.
		 */
		const Cat* beans = new Cat("Beans");
		std::cout << "this type: " << ORANGE << beans->getType() << RESET 
				<< "'s name is: " << ORANGE << beans->getName() << RESET 
				<< ". And it makes this sound: ";
		beans->makeSound();
		
		// Creates a Cat object named paws
		Cat paws("Paws");
		std::cout << "this type before copy: " << ORANGE << paws.getType() << RESET 
				<< "'s name is: " << ORANGE << paws.getName() << RESET 
				<< ". And it makes this sound: ";
		paws.makeSound();
		
		// Uses the copy assignment operator
		paws = *beans;
		std::cout << "this type after copy: " << ORANGE << paws.getType() << RESET 
				<< "'s name is: " << ORANGE << paws.getName() << RESET 
				<< ". And it makes this sound: ";
		paws.makeSound();
		
		// paws object will automatically manage its memory when it goes out of scope,
		// so we don't need to delete it manually.
		delete beans;

		/**
		 * Pointer Assignment: 
		 * In this example, we copy pointers, not the actual objects they point to. 
		 * This can lead to memory management issues, such as the double delete problem.
		 */
		const Dog* sprint = new Dog("Sprint");
		std::cout << "this type: " << ORANGE << sprint->getType() << RESET 
				<< "'s name is: " << ORANGE << sprint->getName() << RESET 
				<< ". And it makes this sound: ";
		sprint->makeSound();
		
		// Creates a new Dog object and assigns its pointer to frankie
		const Dog* frankie = new Dog("Frankie");
		std::cout << "this type before pointer assignment: " << ORANGE << frankie->getType() << RESET 
				<< "'s name is: " << ORANGE << frankie->getName() << RESET 
				<< ". And it makes this sound: ";
		frankie->makeSound();
		
		// Deletes the original Dog object pointed to by frankie to avoid memory leak
		delete frankie;
		frankie = sprint;
		std::cout << "this type after pointer assignment: " << ORANGE << frankie->getType() << RESET 
				<< "'s name is: " << ORANGE << frankie->getName() << RESET 
				<< ". And it makes this sound: ";
		frankie->makeSound();
		
		// Deletes the object that sprint points to, which is the same object that frankie now points to.
		delete sprint;
		std::cout << std::endl;
	}
	{
		std::cout  << "\n" <<  BOLD_TEXT << MAGENTA << "Array of cat's and dogs test" << RESET << std::endl;
		std::cout  <<  BOLD_TEXT << MAGENTA << "Sounds of cats and dogs test" << RESET << std::endl;
		std::cout  <<  BOLD_TEXT << MAGENTA << "Deleting array of cats and dogs test" << RESET << std::endl;
		
		AAnimal* animalCafe[10];
		
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				animalCafe[i] = new Dog();
			else
				animalCafe[i] = new Cat();
		}
		for (int j = 0; j < 10; j++)
			animalCafe[j]->makeSound();
			
		for (int k = 0; k < 10; k++)
			delete animalCafe[k];	
	}
	{
		std::cout << "\n" <<  BOLD_TEXT << MAGENTA << "Giving cat ideas test" << RESET << std::endl;
		
		Cat* cat = new Cat();
		
		for (int i = 0; i < 100; i++) 
		{
			if (i % 2 == 0)
				cat->setIdea(i, "omg magic red dot!!\n");
			else
				cat->setIdea(i, "hmm....I want attention\n");
		}
		for (int i = 0; i < 10; i++)
			std::cout << cat->getIdea(i) << std::endl;
			
		delete cat;
	}
	{
		std::cout << "\n" << BOLD_TEXT << MAGENTA << "Giving dog ideas test" << RESET << std::endl;
		
		Dog dog;
		for (int j = 0; j < 100; j++) 
			dog.setIdea(j, "hmm fooood");
		
		Dog newDog;
		newDog = dog;
		
		for (int j = 0; j < 100; j++) 
			newDog.setIdea(j, "MUST GET THE SOCK!!!");
		
		for (int j = 0; j < 10; j++)
			std::cout << dog.getIdea(j) << std::endl;
			
		for (int j = 0; j < 10; j++)
			std::cout << newDog.getIdea(j) << std::endl;
	}
	/**
	 * A shallow copy occurs when an object is copied, 
	 * but the copy only replicates the memory addresses of the dynamically allocated resources (such as pointers), 
	 * rather than duplicating the actual data those pointers reference.
	 * 
	 * Dog::Dog(const Dog& copy) : Animal(copy), _brain(copy._brain) {
	 * std::cout << BLUE << "Dog " << RESET << "shallow copy constructor called" << RESET << std::endl; }
	 * instead of using new
	*/
	{
		std::cout << "\n" << BOLD_TEXT << MAGENTA << "Giving dog same ideas test" << RESET << std::endl;
		std::cout << "\n" << BOLD_TEXT << MAGENTA << "Testing for deep copy" << RESET << std::endl;

		Dog badDog;
		
		for (int j = 0; j < 100; j++) 
			badDog.setIdea(j, "hmm fooood");
		
		for (int j = 0; j < 10; j++)
			std::cout << badDog.getIdea(j) << std::endl;
		
		Dog newBadDog;
		newBadDog = badDog;
		
		std::cout << "after assignment" << std::endl;
		for (int j = 0; j < 10; j++)
			std::cout << badDog.getIdea(j) << std::endl;
		
		for (int j = 0; j < 10; j++)
			std::cout << newBadDog.getIdea(j) << std::endl;


		if (badDog.getIdea(1) == newBadDog.getIdea(1))
			std::cout << "Shallow copy detected!" << std::endl;
		else
			std::cout << "Deep copy detected!" << std::endl;
	}
	return 0;
}