/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 18:52:51 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/08 15:30:36 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

/**
 * In the constructor of HumanB, initialize _weapon to nullptr to ensure it is not a dangling pointer
 */
HumanB::HumanB(const std::string& givenName) : _name(givenName), _weapon(nullptr)
{
	std::cout << _name << ": constructor called" << std::endl;

}

HumanB::~HumanB()
{
	std::cout << _name << ": deconstructor called" << std::endl;	
}

void HumanB::setWeapon(Weapon& givenWeapon)
{
	_weapon = &givenWeapon;
	return ;
}

void HumanB::attack() const
{
	if (_weapon)
		std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
	else
			std::cout << _name << " has no weapon, better run fast" << std::endl;
	return ;
}

