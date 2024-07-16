/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/13 22:18:09 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/13 22:22:09 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();											//default constructor
		FragTrap(const std::string& Name);					//constructor with parameters
		FragTrap(const FragTrap& copy);						//copy constructor
		const FragTrap& operator=(const FragTrap& copy);	//copy assignment operator overload
		~FragTrap();
		
		void highFivesGuys(void);
};