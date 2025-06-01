/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/30 19:18:42 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/08 14:28:47 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AForm.hpp"

//default lowest grade
AForm::AForm() : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150){
	std::cout << BLUE << "AForm default constructor called" << RESET << std::endl;
}

/**
 * The constructor takes the name as a const std::string&
 * to avoid issues with temporary objects
*/
AForm::AForm(const std::string &name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade){
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	_signed = false;
	std::cout << BLUE << "AForm parametric constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade){
	std::cout << BLUE << "AForm copy constructor called" << RESET << std::endl;
}

AForm& AForm::operator=(const AForm &copy){
	std::cout << BLUE << "AForm operator overloader called" << RESET << std::endl;
	if (this != &copy)
		_signed = copy._signed;
	return *this;
}

AForm::~AForm(){
	std::cout << RED << "AForm destructor called" << RESET << std::endl;
}

std::string const & AForm::getName() const{
	return this->_name;
}

bool AForm::getSigned() const{
	return this->_signed;
}

int AForm::getSignGrade() const{
	return this->_signGrade;
}

int AForm::getExecuteGrade() const{
	return this->_executeGrade;
}

void AForm::beSigned(Bureaucrat bureaucrat){
	if (bureaucrat.getGrade() <= this->_signGrade)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const{
	    if (!this->getSigned())
        throw NotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw GradeTooLowException();
    action();
}

std::ostream & operator<<(std::ostream & stream, const AForm& form){
	stream << ORANGE <<"form name: "
	<< RESET << YELLOW << form.getName()
	<< RESET << ORANGE << ", form sign status " 
	<< RESET << YELLOW << std::boolalpha << form.getSigned() 
	<< RESET << ORANGE << ", form signGrade " 
	<< RESET << YELLOW << form.getSignGrade()
	<< RESET << ORANGE << ", form executeGrade " 
	<< RESET << YELLOW << form.getExecuteGrade() 
	<< RESET << std::endl;
	return stream;
}