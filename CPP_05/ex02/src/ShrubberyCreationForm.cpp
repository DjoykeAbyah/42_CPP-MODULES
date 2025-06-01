/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 12:58:21 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/08 14:30:27 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("Default target"){
	std::cout << BLUE << "Shrubbery constructor called" << RESET << std::endl;
}

/**
 * The constructor takes the name as a const std::string&
 * to avoid issues with temporary objects
*/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), _target(target){
	std::cout << BLUE << "Shrubbery parametric constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target){
	std::cout << BLUE << "Shrubbery copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
	std::cout << BLUE << "Shrubbery operator overloader called" << RESET << std::endl;
	if (this != &copy)
		AForm::operator=(copy); // Call base class assignment operator
        // _target is const, no need to assign
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << RED << "Shrubbery destructor called " << RESET << std::endl;
}

/**
 * @note The std::ios_base::failure exception is used to signal errors in file and stream operations, such as:
 * Failing to open a file.
 * Failing to read from or write to a stream.
 * Other I/O-related errors.
 */
void ShrubberyCreationForm::action() const{
	try {
		std::string filename = this->_target + "_shrubbery.txt";
		std::ofstream outfile(filename);
		if (!outfile){
			throw std::ios_base::failure("Failed to open file");
		} 
		outfile << ASCII_TREE;
		outfile.close();
		std::cout << GREEN << "Shrubbery has been created at " << BOLD_TEXT << filename << RESET << std::endl;
	}
	catch (const std::ios_base::failure& e){
		std::cout << "Exception caught: " << e.what() << std::endl;;
	}
}		