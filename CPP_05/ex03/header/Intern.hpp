/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 16:59:50 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/08 13:53:33 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define BOLD_TEXT "\033[1m"
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define ORANGE "\033[38;2;255;165;0m"

#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

/**
 * Intern is stateless (i.e., it does not have any member variables that need to be copied), 
 * then it makes sense to have a no-op assignment operator.
 */
class Intern
{	
	public:
	
		Intern();
		Intern(const Intern &copy);
		Intern& operator=(const Intern &copy);
		~Intern();
		
		AForm* makeForm(std::string formName, std::string formTarget);
		
		// creation function
		typedef AForm* (*FormCreator)(const std::string &target);

		/**
		 * FormType is a struct that contains a std::string for the form name
		 * and a FormCreator function pointer for the corresponding creation function
		 */
		struct FormType{
			std::string name;
			FormCreator creatorName;
		};
		
		static AForm* createRobotomyRequestForm(const std::string &target);
		static AForm* createPresidentialPardonForm(const std::string &target);
		static AForm* createShrubberyCreationForm(const std::string &target);
};
