/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 12:58:16 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/08 14:29:43 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("Default target"){
	std::cout << "Presidential constructor called" << std::endl;
}

/**
 * The constructor takes the name as a const std::string&
 * to avoid issues with temporary objects
*/
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Default Presidential Creation Form", 25, 5), _target(target){
	std::cout << "Presidential parametric constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target){
	std::cout << "Presidential copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	std::cout << "Presidential operator overloader called" << std::endl;
	if (this != &copy)
		AForm::operator=(copy); // Call base class assignment operator
        // _target is const, no need to assign
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Presidential destructor called " << std::endl;
}

void PresidentialPardonForm::action() const {
		std::cout << BOLD_TEXT << MAGENTA << this->_target << RESET 
		<< MAGENTA << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
	}