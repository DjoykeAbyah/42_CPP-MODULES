/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 19:21:34 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/20 17:57:44 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriasource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		int 		_indexCupboard;
		AMateria* 	_cupboardInventory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& copy);
		virtual ~MateriaSource();

		void learnMateria(AMateria* m) override;
		AMateria* createMateria(std::string const & type) override;
};

#endif