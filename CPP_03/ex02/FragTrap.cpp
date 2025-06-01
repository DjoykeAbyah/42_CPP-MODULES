/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/13 22:18:07 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/15 16:55:34 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	this->setName("Default FragTrap");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setMaxHitPoints(100);
	std::cout << "FragTrap default constructor called and created " 
		<< MAGENTA << this->getName() << RESET << std::endl;
	std::cout << CYAN <<"Stats are: " << RESET << *this << std::endl;
}

FragTrap::FragTrap(const std::string& Name) : ClapTrap(Name){
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setMaxHitPoints(100);
	std::cout << "FragTrap parametric constructor called and created " 
		<< MAGENTA << Name << RESET << std::endl; 	
	std::cout << CYAN << "Stats are: " << RESET << *this << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy){
	*this = copy;
	std::cout << "FragTrap copy constructor called and created " 
		<< MAGENTA << this->_name << RESET << std::endl;
	std::cout << CYAN << "Stats are: " << RESET << *this << std::endl;
}

const FragTrap& FragTrap::operator=(const FragTrap& copy){
	if (this != &copy){
		ClapTrap::operator=(copy);
	}
	std::cout << BLUE << "FragTrap copy assignment operator overloader called" << RESET << "\n\n";
	return *this;
}

FragTrap::~FragTrap(){
		std::cout << RED << "FragTrap deconstructor called. Oh no it destroyed " << RESET << MAGENTA << this->_name << "!" << RESET << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << MAGENTA << this->getName() << RESET << YELLOW << " can I get a highfive guys?" << RESET << std::endl;

}