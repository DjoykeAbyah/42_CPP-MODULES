/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 12:58:19 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/03 16:53:49 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("Default target"){
	std::cout << BLUE << "Robotomy constructor called" << RESET << std::endl;
}

/**
 * The constructor takes the name as a const std::string&
 * to avoid issues with temporary objects
*/
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Default Robotomy Creation Form", 72, 45), _target(target){
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
			
		else {
			if (rand() % 2 == 0)
				std::cout << "DRILLING NOICES " << this->_target << " has been robotomized successfully" << std::endl;
			else
				std::cout << "DRILLING NOICES " << this->_target << " has not been robotomized" << std::endl;
		}
	}
	catch (const std::exception& e){
		std::cout << "Exception caught: " << e.what() << std::endl;;
	}
}