/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 16:59:50 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/07 18:11:15 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
