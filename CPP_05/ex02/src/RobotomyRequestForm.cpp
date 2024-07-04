/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 12:58:19 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/04 19:48:52 by dreijans      ########   odam.nl         */
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	
	try {
		if (!this->getSigned()){
			throw NotSignedException();
		}
		
		else if (executor.getGrade() > this->getExecuteGrade()){
			throw AForm::GradeTooLowException();
		}
		
		std::srand(static_cast<unsigned>(std::time(NULL)));
		unsigned int i = rand();
		
		std::cout << BOLD_TEXT << MAGENTA << "DRILLING NOICES " << RESET <<	std::endl;
		if (i % 2 == 0)
			std::cout << this->_target << GREEN << " has been robotomized successfully" << RESET << std::endl;
		else
			std::cout << this->_target << RED << " has not been robotomized" << RESET << std::endl;
	}
	catch (const std::exception& e){
		std::cout << "Exception caught: " << e.what() << std::endl;
		std::cout << executor.getName() << YELLOW << " couldn't execute " << RESET << this->getName() << std::endl;
		return ;
	}
	std::cout << executor.getName() << GREEN << " executed " << RESET << this->getName() << std::endl;
}