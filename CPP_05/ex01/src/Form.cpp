/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/30 19:18:42 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/03 11:32:53 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Form.hpp"

//default lowest grade
Form::Form() : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150){
	std::cout << BLUE << "Form default constructor called" << RESET << std::endl;
}

/**
 * The constructor takes the name as a const std::string&
 * to avoid issues with temporary objects
*/
Form::Form(const std::string &name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade){
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	_signed = false;
	std::cout << BLUE << "Form parametric constructor called" << RESET << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade){
	std::cout << BLUE << "Form copy constructor called" << RESET << std::endl;
}

Form& Form::operator=(const Form &copy){
	std::cout << BLUE << "operator overloader called" << RESET << std::endl;
	if (this != &copy)
		_signed = copy._signed;
	return *this;
}

Form::~Form(){
	std::cout << RED << "destructor called for Form named: " << RESET << std::endl;
}

std::string const & Form::getName() const{
	return this->_name;
}

bool Form::getSigned() const{
	return this->_signed;
}

int Form::getSignGrade() const{
	return this->_signGrade;
}

int Form::getExecuteGrade() const{
	return this->_executeGrade;
}

void Form::beSigned(Bureaucrat bureaucrat){
	if (bureaucrat.getGrade() <= this->_signGrade)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

/**
 * @todo write an overload of the insertion («) operator that prints all the form’s informations
*/
std::ostream & operator<<(std::ostream & stream, const Form& form){
	stream << ORANGE <<"form name: "
	<< RESET << YELLOW << form.getName()
	<< RESET << ORANGE << ", form sign status " 
	<< RESET << YELLOW << form.getSigned() 
	<< RESET << ORANGE << ", form signGrade " 
	<< RESET << YELLOW << form.getSignGrade()
	<< RESET << ORANGE << ", form executeGrade " 
	<< RESET << YELLOW << form.getExecuteGrade() 
	<< RESET << std::endl;
	return stream;
}