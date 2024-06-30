/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:04:25 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/30 18:49:28 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//default lowest grade
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
	std::cout << BLUE << "default constructor created, bureaucrat named: " << RESET 
	<< CYAN << _name << RESET << BLUE << " with grade: " 
	<< RESET << CYAN << _grade << RESET << std::endl;
}

/**
 * The constructor takes the name as a const std::string&
 * to avoid issues with temporary objects
*/
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << BLUE << "parametric constructor created, bureaucrat named: " 
	<< RESET << CYAN << _name << RESET << BLUE << " with grade: " 
	<< RESET << CYAN << _grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade){
	std::cout << BLUE << "copy constructor created, bureaucrat named: " 
	<< RESET << CYAN << _name << RESET << BLUE << " with grade: " 
	<< RESET << CYAN << _grade << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy){
	std::cout << BLUE << "copy assignment overloader created, bureaucrat named: " 
	<< RESET << CYAN << _name << RESET << BLUE << " with grade: " 
	<< RESET << CYAN << _grade << RESET << std::endl;
	// Only _grade can be changed as _name is const
	if (this != &copy)
		_grade = copy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << RED << "destructor called for bureaucrat named: " << RESET 
	<< MAGENTA << _name << RESET << RED << " with grade: " 
	<< RESET << MAGENTA << _grade << RESET << std::endl;	
}

std::string const & Bureaucrat::getName() const{
	return this->_name;
}

int Bureaucrat::getGrade() const{
	return this->_grade;
}

//throw exception if out of range, incrementing means grade--
void Bureaucrat::incrementGrade(){
	if (this->_grade -1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

//throw exception if out of range, decrementing means grade++
void Bureaucrat::decrementGrade(){
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream & operator<<(std::ostream & stream, const Bureaucrat& bureaucrat){
	stream << ORANGE <<"bureaucrat name: "
	<< RESET << YELLOW << bureaucrat.getName() 
	<< RESET << ORANGE << ", bureaucrat grade " 
	<< RESET << YELLOW << bureaucrat.getGrade() 
	<< RESET << std::endl;
	return stream;
}