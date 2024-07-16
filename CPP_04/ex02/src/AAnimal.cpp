/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/16 21:34:47 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/19 18:09:19 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal"), _name("AAnimal name"){
	std::cout << MAGENTA << "AAnimal " << RESET << "default constructor called"<< RESET << std::endl;
}

AAnimal::AAnimal(const std::string& name) : _type("AAnimal"), _name(name){
	std::cout << MAGENTA << "AAnimal " << RESET << "parametric constructor called"<< RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : _type(copy._type), _name(copy._name){
	std::cout << MAGENTA << "AAnimal " << RESET << "copy constructor called" << RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& copy){
	std::cout << MAGENTA << "AAnimal " << RESET << YELLOW << 
	"copy assignment operator overloader called" << RESET << std::endl;
	if (this != &copy){
        this->_type = copy._type;
        this->_name = copy._name;
	}
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << MAGENTA << "AAnimal " << RESET << RED << "AAnimal destructor called" << RESET << std::endl;
}

void AAnimal::setType(const std::string& type){
	this->_type = type;
}

void AAnimal::setName(const std::string& name) {
    this->_name = name;
}

const std::string& AAnimal::getType() const{
	return this->_type;
}

const std::string& AAnimal::getName() const {
	return this->_name;
}
