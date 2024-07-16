/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 20:16:11 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/18 15:05:39 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called"<< RESET << std::endl;
}

WrongCat::WrongCat(const std::string& name) : WrongAnimal(name){
	std::cout << "WrongCat parametric constructor called"<< RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy){
	std::cout << "WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy){
	std::cout << BLUE << "WrongCat copy assignment operator overloader called" << RESET << "\n\n";
	if (this != &copy)
		this->setType(copy.getType());
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << GREEN << "Wrong Meow" << RESET << std::endl;
}