/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 12:58:19 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/03 15:34:01 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("Default target"){
	std::cout << BLUE << "Shrubbery constructor called" << RESET << std::endl;
}

/**
 * The constructor takes the name as a const std::string&
 * to avoid issues with temporary objects
*/
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Default Shrubbery Creation Form", 145, 137), _target(target){
	std::cout << BLUE << "Shrubbery parametric constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target){
	std::cout << BLUE << "Shrubbery copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
	std::cout << BLUE << "Shrubbery operator overloader called" << RESET << std::endl;
	if (this != &copy)
		AForm::operator=(copy); // Call base class assignment operator
        // _target is const, no need to assign
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << RED << "Shrubbery destructor called " << RESET << std::endl;
}

/**
 * @todo make function
 */
void RobotomyRequestForm::execute(Bureaucrat const & executor) const{

}