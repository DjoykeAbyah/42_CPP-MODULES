/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 12:58:19 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/08 14:30:00 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

RobotomyRequestForm::RobotomyRequestForm() : _target("Default target"){
	std::cout << BLUE << "Robotomy constructor called" << RESET << std::endl;
}

/**
 * The constructor takes the name as a const std::string&
 * to avoid issues with temporary objects
*/
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Creation Form", 72, 45), _target(target){
	std::cout << BLUE << "Robotomy parametric constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target){
	std::cout << BLUE << "Robotomy copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
	std::cout << BLUE << "Robotomy operator overloader called" << RESET << std::endl;
	if (this != &copy)
		AForm::operator=(copy); // Call base class assignment operator
        // _target is const, no need to assign
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << RED << "Robotomy destructor called " << RESET << std::endl;
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