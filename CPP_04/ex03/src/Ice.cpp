/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 16:16:23 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/21 22:27:24 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria(){
	this->_type = "ice";
	std::cout << BLUE << "Ice " << RESET << "default constructor called" << RESET << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type){
	std::cout << BLUE << "Ice " << RESET << "parametric constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy){
	std::cout << BLUE << "Ice " << RESET << "copy constructor called" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& copy){
	std::cout << BLUE << "Ice " << RESET << YELLOW << 
	"copy assignment operator overloader called" << RESET << std::endl;
	if (this != &copy)
		AMateria::operator=(copy);
	return *this;
}

Ice::~Ice(){
	std::cout << BLUE << "Ice " << RESET << RED << "destructor called" << RESET << std::endl;	
}

Ice* Ice::clone() const{
	return new Ice(*this);
}

void Ice::use(ICharacter& target){
	std::cout << CYAN << "* shoots an ice bolt at " 
	<< YELLOW << target.getName() << RESET << CYAN <<  "*" << RESET << std::endl;
}