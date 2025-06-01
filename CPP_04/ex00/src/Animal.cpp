/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/16 21:34:47 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/19 15:46:38 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.hpp"

Animal::Animal() : _type("Animal"), _name("Animal name"){
	std::cout << "Animal default constructor called"<< RESET << std::endl;
}

Animal::Animal(const std::string& name) : _type("Animal"), _name(name){
	std::cout << "Animal parametric constructor called"<< RESET << std::endl;
}

/**
 * @note	maybe call parametric constructor instead of current assignment list
*/
Animal::Animal(const Animal& copy) : _type(copy._type), _name(copy._name){
	std::cout << "Animal copy constructor called" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& copy){
	std::cout << BLUE << "Animal copy assignment operator overloader called" << RESET << "\n\n";
	if (this != &copy)
	{
        this->_type = copy._type;
        this->_name = copy._name;
	}
	return *this;
}

Animal::~Animal(){
	std::cout << RED << "Animal destructor called" << RESET << std::endl;
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
