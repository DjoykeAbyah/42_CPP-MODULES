/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 18:47:18 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/22 17:17:15 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

AMateria* Character::floor[200] = {NULL};
int Character::floorIndex = 0;

Character::Character() : _name("Default"), _inventoryIndex(0){
	std::cout << BLUE << "Character " << RESET << "default constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(std::string const & name) : _name(name), _inventoryIndex(0){
	std::cout << BLUE << "Character " << RESET << "parametric constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& copy) : _name(copy._name), _inventoryIndex(copy._inventoryIndex) {
	std::cout << BLUE << "Character " << RESET << "copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++){
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& copy){
	std::cout << BLUE << "Character " << RESET << YELLOW << 
	"copy assignment operator overloader called" << RESET << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
			delete _inventory[i];
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = copy._inventory[i]->clone();
	}
	return *this;	
}

Character::~Character(){
	std::cout << MAGENTA << "Character " << RESET << RED << " destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

void Character::setName(const std::string name){
	this->_name = name;
}

std::string const & Character::getName() const{
	return this->_name;
}

void Character::equip(AMateria* m){
	if (!m)
		return;
	if (_inventoryIndex > 3)
	{
		std::cout << "cupboard is already full" << std::endl;
		return ;
	}
	this->_inventory[_inventoryIndex] = m;
	_inventoryIndex++;
}

void Character::unequip(int idx){
    if ((idx >= 0 && idx < 4) && _inventory[idx])
    {
        if (floorIndex < 200)
        {
            floor[floorIndex] = _inventory[idx];//move item to the floor
            floorIndex++;
            _inventory[idx] = nullptr;//marks it in the inventory as empty
        }
        _inventoryIndex--;
    }
	std::cout << "* Put item on the floor *" << std::endl;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx >= _inventoryIndex || !_inventory[idx])
		std::cout << "Nothing there to use" << std::endl;
	else
		_inventory[idx]->use(target);//AMateria attribute uses the AMateria function
}

void Character::printInventory() const {
    std::cout << "Inventory of " << _name << ":" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i]) {
            std::cout << "- Slot " << i << ": " << _inventory[i]->getType() << std::endl;
        } else {
            std::cout << "- Slot " << i << ": empty" << std::endl;
        }
    }
}