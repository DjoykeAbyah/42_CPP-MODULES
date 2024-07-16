/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 20:16:11 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/19 13:33:07 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	this->_type = "WrongCat";
	std::cout << BLUE << "WrongCat " << RESET << "default constructor called"<< RESET << std::endl;
}

WrongCat::WrongCat(const std::string& name) : WrongAnimal(name){
	std::cout << BLUE << "WrongCat " << RESET << "parametric constructor called"<< RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy){
	std::cout << BLUE << "WrongCat " << RESET << "copy constructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy){
	std::cout << BLUE << "WrongCat " << RESET << YELLOW << 
	"copy assignment operator overloader called" << RESET << std::endl;
	if (this != &copy)
		this->setType(copy.getType());
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << BLUE << "WrongCat " << RESET << RED << "destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << GREEN << "Wrong Meow" << RESET << std::endl;
}