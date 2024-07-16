/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 18:03:07 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/15 19:04:29 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
 * 
 * fragtrap: 
 * hitpoints = 100
 * energy points = 100;
 * attack damage = 30;
*/
int main()
{
	ClapTrap clapTrap1;
	ClapTrap clapTrap2("ClapTrap Sally");
	ScavTrap scavTrap1;
	ScavTrap scavTrap2("ScavTrap Gerald");
	FragTrap fragTrap1;
	FragTrap fragTrap2("Fragtrap Hank");
	
	//sequence of calling the methods
	fragTrap1.attack(fragTrap2.getName());
	fragTrap2.takeDamage(8);
	fragTrap2.beRepaired(4);
	
	std::cout << BLUE << std::endl << "stat update!" << RESET << std::endl;
	std::cout << clapTrap1 << clapTrap2;
	std::cout << scavTrap1 << scavTrap2;
	std::cout << fragTrap1 << fragTrap2 << std::endl;

	//check if fragtrap can attack claptrap and scavtrap
	fragTrap2.attack(clapTrap1.getName());
	fragTrap2.attack(scavTrap1.getName());

	std::cout << BLUE << std::endl << "stat update!" << RESET << std::endl;
	std::cout << clapTrap1 << clapTrap2;
	std::cout << scavTrap1 << scavTrap2;
	std::cout << fragTrap1 << fragTrap2 << std::endl;
	
	//over the max hitpoints repair test
	scavTrap1.takeDamage(10);
	scavTrap1.beRepaired(110);

	std::cout << BLUE << std::endl << "stat update!" << RESET << std::endl;
	std::cout << clapTrap1 << clapTrap2;
	std::cout << scavTrap1 << scavTrap2;
	std::cout << fragTrap1 << fragTrap2 << std::endl;
	
	//normal damage and repair test
	fragTrap2.takeDamage(10);
	fragTrap2.beRepaired(5);

	std::cout << BLUE << std::endl << "stat update!" << RESET << std::endl;
	std::cout << clapTrap1 << clapTrap2;
	std::cout << scavTrap1 << scavTrap2;
	std::cout << fragTrap1 << fragTrap2 << std::endl;
	
	//some more tests with guarding gate method
	fragTrap1.beRepaired(1);
	fragTrap2.beRepaired(40);
	fragTrap2.takeDamage(100);
	scavTrap1.guardGate();

	std::cout << BLUE << std::endl << "stat update!" << RESET << std::endl;
	std::cout << clapTrap1 << clapTrap2;
	std::cout << scavTrap1 << scavTrap2 << std::endl;
	
	//test with can't take more damage, can't attack and attacking itself
	clapTrap2.attack(fragTrap2.getName());
	fragTrap2.takeDamage(100);
	fragTrap2.attack(scavTrap2.getName());
	fragTrap1.attack(fragTrap1.getName());
	//high five test
	fragTrap1.highFivesGuys();
	
	return 0;
}