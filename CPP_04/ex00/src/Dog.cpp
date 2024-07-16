/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 15:52:14 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/18 15:10:57 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Dog.hpp"

Dog::Dog() : Animal(){
	this->_type = "Dog";
	std::cout << "Dog default constructor called"<< RESET << std::endl;
}

Dog::Dog(const std::string& name) : Animal(name){
	std::cout << "Dog parametric constructor called"<< RESET << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy){
	std::cout << "Dog copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& copy){
	std::cout << BLUE << "Dog copy assignment operator overloader called" << RESET << "\n\n";
	if (this != &copy)
		Animal::operator=(copy);
	return *this;
}

Dog::~Dog(){
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const{
	std::cout << GREEN << "Woof" << RESET << std::endl;
}