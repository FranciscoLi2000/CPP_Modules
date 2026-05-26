/*
 * ScavTrap Implementation for ex02 (with Virtual Inheritance)
 * Based on ex01 but uses virtual inheritance from ClapTrap.
 */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " is constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " is destroyed!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy to attack!" << std::endl;
		return ;
	}
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target
		<< " with knives, causing " << _attackDamage
		<< " points of piercing damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name
		<< " enters Gate Keeper mode and starts guarding the gate!" << std::endl;
}
