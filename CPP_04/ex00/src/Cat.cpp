/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 15:52:09 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/18 15:04:45 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cat.hpp"

Cat::Cat() : Animal(){
	this->_type = "Cat";
	std::cout << "Cat default constructor called"<< RESET << std::endl;
}

Cat::Cat(const std::string& name) : Animal(name){
	std::cout << "Cat parametric constructor called"<< RESET << std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy){
	std::cout << "Cat copy constructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& copy){
	std::cout << BLUE << "Cat copy assignment operator overloader called" << RESET << "\n\n";
	if (this != &copy)
		Animal::operator=(copy);
	return *this;
}

Cat::~Cat(){
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const{
	std::cout << GREEN << "Meow" << RESET << std::endl;
}