#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name) : _name(name)
{
	int	i;

	for (i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character &other) : _name(other._name)
{
	int	i;

	for (i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	copyInventory(other);
	std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		clearInventory();
		_name = other._name;
		copyInventory(other);
	}
	std::cout << "Character assignment operator called" << std::endl;
	return (*this);
}

Character::~Character(void)
{
	clearInventory();
	std::cout << "Character destructor called" << std::endl;
}

std::string const &Character::getName(void) const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	int	i;

	if (m == NULL)
		return ;
	for (i = 0; i < 4; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (_inventory[idx] == NULL)
		return ;
	_inventory[idx]->use(target);
}

void Character::clearInventory(void)
{
	int	i;

	for (i = 0; i < 4; ++i)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}

void Character::copyInventory(const Character &other)
{
	int	i;

	for (i = 0; i < 4; ++i)
	{
		if (other._inventory[i] != NULL)
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}
