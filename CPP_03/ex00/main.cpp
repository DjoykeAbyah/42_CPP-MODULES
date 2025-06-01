/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 18:03:07 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/15 19:08:03 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**
 * claptrap:
 * hitpoints = 10
 * energy points = 10;
 * attack damage = 0;
*/
int main()
{
	//get user input?
	ClapTrap clapTrap1;
	ClapTrap clapTrap2("Sally");
	
	//sequence of calling the methods
	clapTrap1.attack(clapTrap2.getName());
	clapTrap2.takeDamage(8);
	clapTrap2.beRepaired(4);

	std::cout << BLUE << std::endl << "stat update!" << RESET << std::endl;
	std::cout << clapTrap1 << clapTrap2 << std::endl;

	//over the max hitpoints repair test
	clapTrap1.beRepaired(20);
	clapTrap1.takeDamage(10);
	
	//trying to repair after no hitpoints left
	clapTrap1.beRepaired(10);
	
	//trying to take more damage after no hitpionts left
	clapTrap1.takeDamage(5);

	std::cout << BLUE << std::endl << "stat update!" << RESET <<std::endl;
	std::cout << clapTrap1 << clapTrap2 << std::endl;

	//check if energy points go down after attack
	clapTrap2.attack(clapTrap1.getName());
	//check if can't attack itself
	clapTrap1.attack(clapTrap1.getName());

	//zero energypoints check
	clapTrap2.attack(clapTrap1.getName());
	clapTrap2.attack(clapTrap1.getName());
	clapTrap2.attack(clapTrap1.getName());
	clapTrap2.attack(clapTrap1.getName());
	clapTrap2.attack(clapTrap1.getName());
	clapTrap2.attack(clapTrap1.getName());
	clapTrap2.beRepaired(1);
	clapTrap2.beRepaired(1);
	clapTrap2.attack(clapTrap1.getName());
	
	std::cout << BLUE << std::endl << "stat update!" << RESET <<std::endl;
	std::cout << clapTrap1 << clapTrap2 << std::endl;
	
	return 0;
}