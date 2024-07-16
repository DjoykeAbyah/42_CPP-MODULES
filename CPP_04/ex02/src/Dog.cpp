/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 15:52:14 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/19 16:03:15 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain()){
	this->_type = "Dog";
	std::cout << BLUE << "Dog " << RESET << "default constructor called"<< RESET << std::endl;
}

Dog::Dog(const std::string& name) : AAnimal(name), _brain(new Brain()){
	std::cout << BLUE << "Dog " << RESET << "parametric constructor called"<< RESET << std::endl;
}

Dog::Dog(const Dog& copy) : AAnimal(copy), _brain(new Brain(*copy._brain)){
	std::cout << BLUE << "Dog " << RESET << "copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& copy){
	std::cout << BLUE << "Dog " << RESET << YELLOW << 
	"copy assignment operator overloader called" << RESET << std::endl;
	if (this != &copy)
		AAnimal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
	return *this;
}

Dog::~Dog(){
	delete _brain;
	std::cout << BLUE << "Dog " << RESET << RED << "destructor called" << RESET << std::endl;
}

void Dog::setIdea(int index, const std::string& idea){
	if (index >= 0 && index <= 100)
		this->_brain->setIdeas(index, idea);
	else
		std::cout << YELLOW << "index out of bounds please enter 0-100, this dog is smart enough" << RESET << std::endl;		
}

std::string Dog::getIdea(int index) const{
	if (index >= 0 && index <= 100)
		return this->_brain->getIdeas(index);
	else
		std::cout << YELLOW << "index out of bounds please enter 0-100, not a single thought staring into nothing" << RESET << std::endl;
		return "";
}

void Dog::makeSound() const{
	std::cout << GREEN << "Woof" << RESET << std::endl;
}