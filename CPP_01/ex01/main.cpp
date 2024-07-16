/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 16:31:49 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/03 18:34:41 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
	Zombie* horde = zombieHorde(5, "Horde");

	for (int i = 0; i < 5; i++)	
		horde[i].announce();
		
	delete[] horde;
	return 0;
}