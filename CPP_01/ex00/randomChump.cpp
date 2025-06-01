/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 22:48:07 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/03 17:02:22 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/**
 * allocated zombie on stack
 * will create a zombie and once the scope of this
 * function is done the zombie stops existing
*/
void randomChump(std::string name)
{
	Zombie Chump(name);
	Chump.announce();
}
