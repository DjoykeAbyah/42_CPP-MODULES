/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 16:22:17 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/19 19:20:19 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _indexCupboard(0){
	std::cout << BLUE << "MateriaSource " << RESET << "default constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_cupboardInventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& copy) : _indexCupboard(copy._indexCupboard) {
	std::cout << BLUE << "MateriaSource " << RESET << "copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy._cupboardInventory[i])
			this->_cupboardInventory[i] = copy._cupboardInventory[i]->clone();
		else
			_cupboardInventory[i] = NULL;
	}
	this->_indexCupboard = copy._indexCupboard;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy){
	std::cout << BLUE << "MateriaSource " << RESET << YELLOW << 
	"copy assignment operator overloader called" << RESET << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _cupboardInventory[i];
			this->_cupboardInventory[i] = copy._cupboardInventory[i]->clone();
		}
		this->_indexCupboard = copy._indexCupboard;
	}
	return *this;	
}

MateriaSource::~MateriaSource(){
	std::cout << MAGENTA << "MateriaSource " << RESET << RED << " destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_cupboardInventory[i];
}

/**
 * Copies the Materia passed as a parameter and store it in memory so it can be clone.
 * later. Like the Character, the MateriaSource can know at most 4 Materias. They
 * are not necessarily unique.
*/
void MateriaSource::learnMateria(AMateria* m){
	if (!m)
		return ;
	if (_indexCupboard == 4)
	{
		std::cout << "* cupboard is full *" << std::endl;
		delete m;
		return ;
	}
	std::cout << "* Materia " << YELLOW << m->getType() << RESET << " learned *" << std::endl;
	_cupboardInventory[_indexCupboard] = m;
	_indexCupboard++;
}

/**
 * @brief 
 * 			creates MateriaSource equal to type
 * @return
 * 			Returns 0 if the type is unknown.
 * 			Returns a new Materia (copy of the Materia previously learned)
 * @note 
 * 			_cupboardInventory[i] is a pointer to an object, not an object itself. 
 * 			Therefore, you need to use the -> operator to access the members 
 * 			of the object pointed to by _cupboardInventory[i].
*/
AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++)
	{
		if (_cupboardInventory[i] && type == _cupboardInventory[i]->getType())
			return _cupboardInventory[i]->clone();
	}
	std::cout << "* can't create this Materia you call " << YELLOW << type << " *" << RESET << std::endl;
	return NULL;
}
