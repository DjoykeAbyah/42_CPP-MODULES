/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 18:53:00 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/04 19:32:56 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(const std::string& givenType) : _type(givenType)
{
	std::cout << "weapon constructor called" << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "weapon deconstructor called" << std::endl;
	return ;	
}

const std::string& Weapon::getType() const
{
	return _type;
}

void Weapon::setType(std::string givenType)
{
	_type = givenType;
}