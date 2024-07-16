/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 16:14:22 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/19 19:44:10 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice(std::string const & type);
		Ice(const Ice& copy);
		Ice& operator=(const Ice& copy);
		virtual ~Ice();

		Ice* clone() const override;
		void use(ICharacter& target) override;
};

#endif