/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 18:52:54 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/04 18:01:01 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
# define HUMAN_B_H

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon* _weapon; //pointer is always a different address, can initialise as NULL
		std::string _name;
		
	public:
		HumanB(const std::string& givenName);//no weapon in constructor
		~HumanB();

		void attack() const;
		void setWeapon(Weapon& givenWeapon);
};

#endif