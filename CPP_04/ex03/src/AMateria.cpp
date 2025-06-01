/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 16:09:04 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/19 20:36:01 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("Default"){
	std::cout << MAGENTA << "AMateria " << RESET << "default constructor called"<< RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type){
	std::cout << MAGENTA << "AMateria " << RESET << "parametric constructor called"<< RESET << std::endl;

}

AMateria::AMateria(const AMateria& copy) : _type(copy._type){
	std::cout << MAGENTA << "AMateria " << RESET << "copy constructor called" << RESET << std::endl;	
}

AMateria& AMateria::operator=(const AMateria& copy){
	std::cout << MAGENTA << "AMateria " << RESET << YELLOW << 
	"copy assignment operator overloader called" << RESET << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

AMateria::~AMateria(){
	std::cout << MAGENTA << "AMateria " << RESET << RED << " destructor called" << RESET << std::endl;
}

void AMateria::setType(const std::string type){
	this->_type = type;
}

std::string const &AMateria::getType() const{
	return this->_type;
}

void AMateria::use(ICharacter& target){
	std::cout << CYAN << "* does something concerning " 
	<< YELLOW << target.getName() << RESET << CYAN <<  "*" << RESET << std::endl;
}