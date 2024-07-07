/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 16:59:27 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/07 15:44:29 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"

Intern::Intern(){};

Intern::Intern(const Intern &copy){
	*this = copy;
}

Intern& Intern::operator=(const Intern &copy){
	if (this != &copy)
		//Intern had no data members to copy
	return *this;
}

Intern::~Intern(){};

AForm* Intern::makeForm(std::string &formName, std::string &formTarget){
	
}