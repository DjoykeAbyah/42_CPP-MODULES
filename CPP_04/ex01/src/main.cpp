/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/16 21:34:56 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/22 17:38:16 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.hpp"
#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include "../header/Brain.hpp"
#include "../header/WrongAnimal.hpp"
#include "../header/WrongCat.hpp"

/**
 * A shallow copy occurs when an object is copied, 
 * but the copy only replicates the memory addresses of the dynamically allocated resources (such as pointers), 
 * rather than duplicating the actual data those pointers reference.
 * 
 * Dog::Dog(const Dog& copy) : Animal(copy), _brain(copy._brain) {
 * std::cout << BLUE << "Dog " << RESET << "shallow copy constructor called" << RESET << std::endl; }
 * instead of using new
*/
int main() {
    {
        std::cout << "\n" << BOLD_TEXT << MAGENTA << "Basic test from subject" << RESET << std::endl;
        
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;    
    }
    {
        std::cout << "\n" << BOLD_TEXT << MAGENTA << "Parametric constructor test" << RESET << std::endl;

        const Animal* fluffy = new Cat("Fluffy");
        const Animal* wouwz = new Cat("Wouwz");
        const Animal* thing = new Animal("Thing");
        const WrongAnimal* whatsThat = new WrongAnimal("Iewl");
        const WrongCat* puma = new WrongCat("Puma");

        std::cout << "this type: " << ORANGE << fluffy->getType() << RESET 
                  << "'s name is: " << ORANGE << fluffy->getName() << RESET 
                  << ". And it makes this sound: ";
        fluffy->makeSound();
        std::cout << "this type: " << ORANGE << wouwz->getType() << RESET 
                  << "'s name is: " << ORANGE << wouwz->getName() << RESET 
                  << ". And it makes this sound: ";
        wouwz->makeSound();
        std::cout << "this type: " << ORANGE << thing->getType() << RESET 
                  << "'s name is: " << ORANGE << thing->getName() << RESET 
                  << ". And it makes this sound: ";
        thing->makeSound(); 
        std::cout << "this type: " << ORANGE << whatsThat->getType() << RESET 
                  << "'s name is: " << ORANGE << whatsThat->getName() << RESET 
                  << ". And it makes this sound: ";
        whatsThat->makeSound();
        std::cout << "this type: " << ORANGE << puma->getType() << RESET 
                  << "'s name is: " << ORANGE << puma->getName() << RESET 
                  << ". And it makes this sound: ";
        puma->makeSound();

        delete fluffy;
        delete wouwz;
        delete thing;
        delete whatsThat;
        delete puma;
    }
    {
        std::cout << "\n" << BOLD_TEXT << MAGENTA << "Copy constructor test" << RESET << std::endl;

        Dog henk("Henk");
        std::cout << "this type: " << ORANGE << henk.getType() << RESET 
                  << "'s name is: " << ORANGE << henk.getName() << RESET 
                  << ". And it makes this sound: ";
        henk.makeSound();
        
        Dog copyHenk(henk);
        std::cout << "this type: " << ORANGE << copyHenk.getType() << RESET 
                  << "'s name is: " << ORANGE << copyHenk.getName() << RESET 
                  << ". And it makes this sound: ";
        copyHenk.makeSound();
    }
    {
        std::cout << "\n" << BOLD_TEXT << MAGENTA << "Copy assignment operator test" << RESET << std::endl;

        const Cat* beans = new Cat("Beans");
        std::cout << "this type: " << ORANGE << beans->getType() << RESET 
                  << "'s name is: " << ORANGE << beans->getName() << RESET 
                  << ". And it makes this sound: ";
        beans->makeSound();
        
        Cat paws("Paws");
        std::cout << "this type before copy: " << ORANGE << paws.getType() << RESET 
                  << "'s name is: " << ORANGE << paws.getName() << RESET 
                  << ". And it makes this sound: ";
        paws.makeSound();
        
        paws = *beans;
        std::cout << "this type after copy: " << ORANGE << paws.getType() << RESET 
                  << "'s name is: " << ORANGE << paws.getName() << RESET 
                  << ". And it makes this sound: ";
        paws.makeSound();
        
        delete beans;

        const Dog* sprint = new Dog("Sprint");
        std::cout << "this type: " << ORANGE << sprint->getType() << RESET 
                  << "'s name is: " << ORANGE << sprint->getName() << RESET 
                  << ". And it makes this sound: ";
        sprint->makeSound();
        
        const Dog* frankie = new Dog("Frankie");
        std::cout << "this type before pointer assignment: " << ORANGE << frankie->getType() << RESET 
                  << "'s name is: " << ORANGE << frankie->getName() << RESET 
                  << ". And it makes this sound: ";
        frankie->makeSound();
        
        delete frankie;
        frankie = sprint;
        std::cout << "this type after pointer assignment: " << ORANGE << frankie->getType() << RESET 
                  << "'s name is: " << ORANGE << frankie->getName() << RESET 
                  << ". And it makes this sound: ";
        frankie->makeSound();
        
        delete sprint;
    }
    {
        std::cout << "\n" << BOLD_TEXT << MAGENTA << "Array of cat's and dogs test" << RESET << std::endl;
        
        Animal* animalCafe[10];
        for (int i = 0; i < 10; i++) {
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
        std::cout << "\n" << BOLD_TEXT << MAGENTA << "Giving cat ideas test" << RESET << std::endl;
        
        Cat* cat = new Cat();
        
        for (int i = 0; i < 100; i++) {
            if (i % 2 == 0)
                cat->setIdea(i, "omg magic red dot!!\n");
            else
                cat->setIdea(i, "hmm....I want attention\n");
        }
        for (int i = 0; i < 10; i++)
            std::cout << cat->getIdea(i);
            
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
    {
        std::cout << "\n" << BOLD_TEXT << MAGENTA << "Giving dog same ideas test" << RESET << std::endl;
        std::cout << "\n" << BOLD_TEXT << MAGENTA << "Testing for deep copy" << RESET << std::endl;

        Dog badDog;
        
        for (int j = 0; j < 100; j++) 
            badDog.setIdea(j, "hmm fooood");
        
        for (int j = 0; j < 10; j++)
            std::cout << badDog.getIdea(j);
        std::cout << std::endl;
        
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
