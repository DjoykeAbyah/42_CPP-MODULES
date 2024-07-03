/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 12:58:16 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/03 16:07:40 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("Default target"){
	std::cout << BLUE << "Shrubbery constructor called" << RESET << std::endl;
}

/**
 * The constructor takes the name as a const std::string&
 * to avoid issues with temporary objects
*/
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Default Shrubbery Creation Form", 145, 137), _target(target){
	std::cout << BLUE << "Shrubbery parametric constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target){
	std::cout << BLUE << "Shrubbery copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	std::cout << BLUE << "Shrubbery operator overloader called" << RESET << std::endl;
	if (this != &copy)
		AForm::operator=(copy); // Call base class assignment operator
        // _target is const, no need to assign
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << RED << "Shrubbery destructor called " << RESET << std::endl;
}

/**
 * @todo make function
 */
void PresidentialPardonForm::execute(Bureaucrat const & executor) const{

}