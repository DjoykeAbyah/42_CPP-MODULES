/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:04:25 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/08 14:29:10 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"

//default lowest grade
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
	std::cout << BLUE << "Bureaucrat default constructor called" << RESET << RESET << std::endl;
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
	std::cout << BLUE << "Bureaucrat parametric constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade){
	std::cout << BLUE << "Bureaucrat copy constructor called" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy){
	std::cout << BLUE << "Bureaucrat copy assignment overloader called " << RESET << std::endl;
	// Only _grade can be changed as _name is const
	if (this != &copy)
		_grade = copy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
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
		form.beSigned(*this);//try to use sign method for this form
		std::cout << this->_name << " signed: " << form.getName() << std::endl;
	}
	catch (const std::exception& e){
		std::cout << this->_name << " couldn't sign: " << form.getName() << " because " << e.what() << std::endl;
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