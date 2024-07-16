/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 22:48:15 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/08 15:17:38 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie
{
	private:
		//member attribute
		std::string _name = "Nameless wierdo";
	
	public:
		Zombie(void);
		Zombie(std::string givenName);
		~Zombie(void);
		
		//member function
		void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif