/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 22:47:20 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/13 22:08:11 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

/**
 * public means accessible from anywhere
 * protected means accessible from an instance of the class or instance of child class
 * private means only accessible from instance of the class
*/
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();											//default constructor
		ScavTrap(const std::string& Name);					//constructor with parameters
		ScavTrap(const ScavTrap& copy);						//copy constructor
		const ScavTrap& operator=(const ScavTrap& copy);	//copy assignment operator overload
		~ScavTrap();
		
		void guardGate();
};
