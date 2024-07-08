/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:04:25 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/08 14:07:41 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"

//default lowest grade
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
	std::cout << "Bureaucrat default constructor called" << std::endl;
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
	std::cout << "Bureaucrat parametric constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade){
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy){
	std::cout << "Bureaucrat copy assignment overloader called " << std::endl;
	// Only _grade can be changed as _name is const
	if (this != &copy)
		_grade = copy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

void Bureaucrat::setGrade(int grade){
	_grade = grade;
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

void Bureaucrat::signForm(AForm& form){
	try {
		form.beSigned(*this);
		std::cout << BLUE << BOLD_TEXT << this->_name << RESET 
		<< GREEN << " signed: " << RESET << BLUE 
		<< form.getName() << RESET << std::endl;
	}
	catch (const std::exception& e){
		std::cout << BLUE << BOLD_TEXT << this->_name << RESET 
		<< RED <<" couldn't sign: " << RESET << BLUE << form.getName() 
		<< " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form){
	try {
		form.execute(*this);
		std::cout << CYAN << BOLD_TEXT << this->_name << RESET 
		<< GREEN << " executed " << RESET << CYAN 
		<< form.getName() << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << CYAN << BOLD_TEXT << this->_name << RESET 
		<< RED << " couldn't execute " << RESET << CYAN 
		<< form.getName() << RESET <<std::endl;
	}
}

std::ostream & operator<<(std::ostream & stream, const Bureaucrat& bureaucrat){
	stream << ORANGE <<"bureaucrat name: "
	<< RESET << YELLOW << bureaucrat.getName() 
	<< RESET << ORANGE << ", bureaucrat grade " 
	<< RESET << YELLOW << bureaucrat.getGrade() 
	<< RESET << std::endl;
	return stream;
}