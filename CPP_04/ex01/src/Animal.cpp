/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/16 21:34:47 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/19 15:46:44 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.hpp"

Animal::Animal() : _type("Animal"), _name("Animal name"){
	std::cout << MAGENTA << "Animal " << RESET << "default constructor called"<< RESET << std::endl;
}

Animal::Animal(const std::string& name) : _type("Animal"), _name(name){
	std::cout << MAGENTA << "Animal " << RESET << "parametric constructor called"<< RESET << std::endl;
}

Animal::Animal(const Animal& copy) : _type(copy._type), _name(copy._name){
	std::cout << MAGENTA << "Animal " << RESET << "copy constructor called" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& copy){
	std::cout << MAGENTA << "Animal " << RESET << YELLOW << 
	"copy assignment operator overloader called" << RESET << std::endl;
	if (this != &copy){
        this->_type = copy._type;
        this->_name = copy._name;
	}
	return *this;
}

Animal::~Animal(){
	std::cout << MAGENTA << "Animal " << RESET << RED << "Animal destructor called" << RESET << std::endl;
}

void Animal::setType(const std::string& type){
	this->_type = type;
}

void Animal::setName(const std::string& name) {
    this->_name = name;
}

const std::string& Animal::getType() const{
	return this->_type;
}

const std::string& Animal::getName() const {
	return this->_name;
}

void Animal::makeSound() const{
	std::cout << GREEN << "Animalll!!!!" << RESET << std::endl;
}
