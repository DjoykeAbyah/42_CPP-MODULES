/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 16:59:27 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/07 19:08:19 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"

Intern::Intern(){};

Intern::Intern(const Intern &copy){
	*this = copy;
}

Intern& Intern::operator=(const Intern &copy){
	(void)copy; //explicitly mark the parameter as unused
	return *this;
}

Intern::~Intern(){};

AForm* Intern::createRobotomyRequestForm(const std::string &target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string &target){
	return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubberyCreationForm(const std::string &target){
	return new ShrubberyCreationForm(target);
}

/**
 * @brief 	- 	FormCreator is a typedef for a function pointer that points to a function returning an AForm*
 * 				and taking a const std::string& as a parameter.
 *			-	formTypes is an array of FormType structs, 
 *				mapping form names to their respective creation functions.
 */
AForm* Intern::makeForm(std::string formName, std::string formTarget){

	FormType formTypes[] = {
		{"robotomy request", &Intern::createRobotomyRequestForm},
		{"presidential pardon", &Intern::createPresidentialPardonForm},
		{"shrubbery creation", &Intern::createShrubberyCreationForm}
	};
	
	for (int i = 0; i < 3; i++){
		if (formName == formTypes[i].name){
			std::cout << "Intern creates " << formName << std::endl;
			return formTypes[i].creatorName(formTarget);
		}
	}
	// throw std::invalid_argument("Intern couldn't create form: " + formName);
	return nullptr;
}