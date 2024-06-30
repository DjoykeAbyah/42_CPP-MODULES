/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:04:25 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/29 17:57:43 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(0){}

/**
 * need to check for to high or too low here too?
*/
Bureaucrat::Bureaucrat(std::string &name, int grade) : _name(name), _grade(grade){}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

Bureaucrat::~Bureaucrat(){}

