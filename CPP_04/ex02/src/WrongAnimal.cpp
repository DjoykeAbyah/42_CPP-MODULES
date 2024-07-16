/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 20:17:11 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/19 15:46:53 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal"), _name("WrongAnimal Name"){
	std::cout << MAGENTA << "WrongAnimal " << RESET << "default constructor called"<< RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& name) : _type("WrongAnimal"), _name(name){
	std::cout << MAGENTA << "WrongAnimal " << RESET << "parametric constructor called"<< RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type), _name(copy._name){
	std::cout << MAGENTA << "WrongAnimal " << RESET << "copy constructor called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy){
	std::cout << MAGENTA << "WrongAnimal " << RESET << YELLOW << 
	"copy assignment operator overloader called" << RESET << std::endl;
	if (this != &copy)
	{
        this->_type = copy._type;
        this->_name = copy._name;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << MAGENTA << "WrongAnimal " << RESET << RED << "destructor called" << RESET << std::endl;
}

void WrongAnimal::setType(const std::string& type){
	this->_type = type;
}

void WrongAnimal::setName(const std::string& name) {
    this->_name = name;
}

const std::string& WrongAnimal::getType() const{
	return this->_type;
}

const std::string& WrongAnimal::getName() const {
	return this->_name;
}

void WrongAnimal::makeSound() const{
	std::cout << GREEN << "WrongAnimalll!!!!" << RESET << std::endl;
}