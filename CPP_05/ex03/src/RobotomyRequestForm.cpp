/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 12:58:19 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/08 14:30:05 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("Default target"){
	std::cout << "Robotomy constructor called" << std::endl;
}

/**
 * The constructor takes the name as a const std::string&
 * to avoid issues with temporary objects
*/
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Default Robotomy Creation Form", 72, 45), _target(target){
	std::cout << "Robotomy parametric constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target){
	std::cout << "Robotomy copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
	std::cout << "Robotomy operator overloader called" << std::endl;
	if (this != &copy)
		AForm::operator=(copy); // Call base class assignment operator
        // _target is const, no need to assign
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Robotomy destructor called " << std::endl;
}

void RobotomyRequestForm::action() const{
	std::cout << ORANGE << "DRILLING NOISES....";
	if (rand() % 2 == 0)
	{
		std::cout << BOLD_TEXT << this->_target << RESET 
		<< GREEN << " has been robotomized successfully" << RESET << std::endl;
		
	}
	else
	{
		std::cout << BOLD_TEXT << this->_target << RESET 
		<< RED << " has not been robotomized" << RESET << std::endl;
	}
}
