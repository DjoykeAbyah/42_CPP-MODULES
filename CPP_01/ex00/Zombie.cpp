/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 22:48:09 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/03 17:19:19 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << Zombie::_name << ": default constructor called" << std::endl;
	return ;
}

/**
 * constructor with parameter
*/
Zombie::Zombie(std::string givenName) : _name(givenName)
{
	std::cout << Zombie::_name << ": constructor called" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::_name << ": destroyed" << std::endl;
	return ;
}

void Zombie::announce(void)
{
	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
