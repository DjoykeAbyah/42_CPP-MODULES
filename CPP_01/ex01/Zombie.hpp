/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 16:31:52 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/03 18:30:19 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(void);
		~Zombie(void);

		void setName(const std::string& givenName);
		void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif