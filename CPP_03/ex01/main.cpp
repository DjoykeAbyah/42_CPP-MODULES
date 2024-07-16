/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 18:03:07 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/15 18:57:52 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/**
 * claptrap:
 * hitpoints = 10
 * energy points = 10;
 * attack damage = 0;
 * 
 * scavtrap:
 * hitpoints = 100
 * energy points = 50;
 * attack damage = 20;
*/
int main()
{
	ClapTrap clapTrap1;
	ClapTrap clapTrap2("ClapTrap Sally");
	ScavTrap scavTrap1;
	ScavTrap scavTrap2("ScavTrap Gerald");
	
	//sequence of calling the methods
	scavTrap1.attack(scavTrap2.getName());
	scavTrap2.takeDamage(8);
	scavTrap2.beRepaired(4);
	
	std::cout << BLUE << std::endl << "stat update!" << RESET << std::endl;
	std::cout << clapTrap1 << clapTrap2;
	std::cout << scavTrap1 << scavTrap2 << std::endl;
	
	//check if scavtrap can attack claptrap
	scavTrap2.attack(clapTrap1.getName());

	std::cout << BLUE << std::endl << "stat update!" << RESET << std::endl;
	std::cout << clapTrap1 << clapTrap2;
	std::cout << scavTrap1 << scavTrap2 << std::endl;

	//over the max hitpoints repair test
	scavTrap1.takeDamage(10);
	scavTrap1.beRepaired(100);
	
	std::cout << BLUE << std::endl << "stat update!" << RESET << std::endl;
	std::cout << clapTrap1 << clapTrap2;
	std::cout << scavTrap1 << scavTrap2 << std::endl;
	
	//normal damage and repair test
	clapTrap2.takeDamage(10);
	clapTrap2.beRepaired(5);

	std::cout << BLUE << std::endl << "stat update!" << RESET << std::endl;
	std::cout << clapTrap1 << clapTrap2;
	std::cout << scavTrap1 << scavTrap2 << std::endl;

	//some more tests with guarding gate method
	scavTrap1.beRepaired(1);
	scavTrap2.beRepaired(40);
	scavTrap2.takeDamage(100);
	scavTrap1.guardGate();

	std::cout << BLUE << std::endl << "stat update!" << RESET << std::endl;
	std::cout << clapTrap1 << clapTrap2;
	std::cout << scavTrap1 << scavTrap2 << std::endl;

	//test with can't take more damage, can't attack and attacking itself
	scavTrap2.attack(clapTrap2.getName());
	clapTrap2.takeDamage(10);
	clapTrap2.attack(scavTrap2.getName());
	scavTrap1.attack(scavTrap1.getName());
	
	return 0;
}