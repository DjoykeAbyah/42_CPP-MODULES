/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 22:46:27 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/08 15:17:04 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie zombie("Sally");
	Zombie zombie1;
	randomChump("Stack Zombie");
	Zombie *testZombie = newZombie("Heap Zombie");
	
	//non static member function call operate on a instance of the class
	zombie.announce();
	zombie1.announce();
	delete testZombie;

	return 0;
}
