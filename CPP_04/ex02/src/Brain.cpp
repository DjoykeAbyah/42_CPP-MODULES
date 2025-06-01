/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 21:08:55 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/19 15:31:07 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Brain.hpp"

Brain::Brain() : _ideas(){
	std::cout << CYAN << "Brain " << RESET << "default constructor called"<< std::endl;
}

Brain::Brain(const Brain& copy) : _ideas(){
	std::cout << CYAN << "Brain " << RESET << "copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& copy){
	std::cout << CYAN << "Brain " << RESET << YELLOW << 
	"copy assignment operator overloader called" << RESET << std::endl;
	if (this != &copy)
		for (int i = 0; i < 100; i++)
			_ideas[i] = copy._ideas[i];
	return *this;
}

Brain::~Brain(){
	std::cout << CYAN << "Brain " << RESET << RED << "destructor called" << RESET << std::endl;
}

std::string Brain::getIdeas(int index) const{
	return this->_ideas[index];
}

void Brain::setIdeas(int index, const std::string& idea){
	this->_ideas[index] = idea;
}