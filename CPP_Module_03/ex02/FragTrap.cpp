/*
 * FragTrap Implementation for ex02 (with Virtual Inheritance)
 * Based on ex00 but uses virtual inheritance from ClapTrap.
 */

#include "FragTrap.hpp"
#include <iostream>

/*
 * Constructor:
 * In virtual inheritance, derived classes must call the virtual base constructor.
 * Syntax is the same: FragTrap::FragTrap(name) : ClapTrap(name)
 * The compiler handles the virtual inheritance complexity.
 */
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " is constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " is destroyed!" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no energy to attack!" << std::endl;
		return ;
	}
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target
		<< " with a grenade, causing " << _attackDamage
		<< " points of explosive damage!" << std::endl;
}

void	FragTrap::highFiveWithGuys(void)
{
	std::cout << "FragTrap " << _name
		<< " offers a high five to everyone around! Give me a high five!" << std::endl;
}
