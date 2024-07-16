/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 16:31:46 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/03 18:35:18 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << Zombie::_name << "default constructor called" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::_name << ": destroyed" << std::endl;
	return ;
}

void Zombie::setName(const std::string& givenName)
{
	_name = givenName;
}

void Zombie::announce(void)
{
	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}