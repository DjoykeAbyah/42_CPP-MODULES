/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/11 21:26:59 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/15 16:41:26 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>

# define BOLD_TEXT "\033[1m"
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"

class ClapTrap
{
	protected:
		std::string		_name;
		int 			_hitPoints;
		int 			_energyPoints;
		int 			_attackDamage;
		int				_maxHitPoints;
		
	public:
		ClapTrap();											//default constructor
		ClapTrap(const std::string& Name);					//constructor with parameters
		ClapTrap(const ClapTrap& copy);						//copy constructor
		const ClapTrap& operator=(const ClapTrap& copy); 	//copy assignment operator overload
		~ClapTrap();

		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		int	getMaxHitPoints() const;
		const std::string& getName() const;

		void setHitPoints(int amount);
		void setEnergyPoints(int amount);
		void setAttackDamage(int amount);
		void setMaxHitPoints(int amount);
		void setName(const std::string& name);
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);	
};

//for debugging
std::ostream& operator<<(std::ostream & stream, const ClapTrap& other);