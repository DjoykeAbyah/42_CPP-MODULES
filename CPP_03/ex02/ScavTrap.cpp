/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 22:47:17 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/15 16:55:03 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	this->setName("Default ScavTrap");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setMaxHitPoints(100);
	std::cout << "ScavTrap default constructor called and created " 
		<< MAGENTA << this->getName() << RESET << std::endl;
	std::cout << CYAN <<"Stats are: " << RESET << *this << std::endl;
}

ScavTrap::ScavTrap(const std::string& Name) : ClapTrap(Name){
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setMaxHitPoints(100);
	std::cout << "ScavTrap parametric constructor called and created " 
		<< MAGENTA << Name << RESET << std::endl; 	
	std::cout << CYAN << "Stats are: " << RESET << *this << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy){
	*this = copy;
	std::cout << "ScavTrap copy constructor called and created " 
		<< MAGENTA << this->_name << RESET << std::endl;
	std::cout << CYAN << "Stats are: " << RESET << *this << std::endl;
}

//is this getting it from ScavTrap or Claptrap??
const ScavTrap& ScavTrap::operator=(const ScavTrap& copy){
	if (this != &copy){
		ClapTrap::operator=(copy);
	}
	std::cout << BLUE << "ScavTrap copy assignment operator overloader called" << RESET << "\n\n";
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << RED << "ScavTrap deconstructor called. Oh no it destroyed " << RESET << MAGENTA << this->_name << "!" << RESET << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << MAGENTA << this->getName() << RESET << YELLOW << " is just guarding the gate guys. Nothing to see here" << RESET << std::endl;
}

