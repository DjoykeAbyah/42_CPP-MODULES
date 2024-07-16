/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 15:52:09 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/19 16:02:51 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal(), _brain(new Brain()){
	this->_type = "Cat";
	std::cout << BLUE << "Cat " << RESET << "default constructor called" << RESET << std::endl;
}

Cat::Cat(const std::string& name) : AAnimal(name), _brain(new Brain()){
	std::cout << BLUE << "Cat " << RESET << "parametric constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& copy) : AAnimal(copy), _brain(new Brain(*copy._brain)){
	std::cout << BLUE << "Cat " << RESET << "copy constructor called" << RESET << std::endl;
}

/**
 * @brief 	copies content of one excisting Cat to another excisting cat
 *			not just shallow copy of the pointer
*/
Cat& Cat::operator=(const Cat& copy){
	std::cout << BLUE << "Cat " << RESET << YELLOW << 
	"copy assignment operator overloader called" << RESET << std::endl;
	if (this != &copy)
		AAnimal::operator=(copy);//copies base class part of cat
		delete _brain;//delete old brain to prevent memory leak
		_brain = new Brain(*copy._brain);// create new brain as deep copy part of copy's brain
	return *this;
}

Cat::~Cat(){
	delete _brain;
	std::cout << BLUE << "Cat " << RESET << RED << "destructor called" << RESET << std::endl;
}

void Cat::setIdea(int index, const std::string& idea){
	if (index >= 0 && index <= 100)
		this->_brain->setIdeas(index, idea);
	else
		std::cout << YELLOW << "index out of bounds please enter 0-100, this cat is smart enough" << RESET << std::endl;
}

std::string Cat::getIdea(int index) const{
	if (index >= 0 && index <= 100)
		return this->_brain->getIdeas(index);
	else
		std::cout << YELLOW << "index out of bounds please enter 0-100, not a single thought behind those eyes" << RESET << std::endl;
		return "";
}

void Cat::makeSound() const{
	std::cout << GREEN << "Meow" << RESET << std::endl;
}
