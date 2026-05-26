#include "ClapTrap.hpp"
#include <iostream>

/*
 * ClapTrap Constructor:
 * Initializes all member variables.
 * Member initialization list (from CPP02) ensures efficient initialization.
 */
ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is constructed!" << std::endl;
}

/*
 * Copy Constructor:
 * From CPP02: Orthodox Canonical Form.
 * Creates an independent copy of another ClapTrap.
 */
ClapTrap::ClapTrap(const ClapTrap &src)
	: _name(src._name), _hitPoints(src._hitPoints),
	  _energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

/*
 * Assignment Operator:
 * From CPP02: Orthodox Canonical Form.
 * Remember: handle self-assignment and return reference to *this.
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

/*
 * Destructor:
 * Cleans up the ClapTrap when it goes out of scope.
 * Not virtual here (only the base class), but we'll make it virtual
 * in derived classes in later exercises.
 */
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

/*
 * attack():
 * ClapTrap attacks a target.
 * From CPP01: We use references here to avoid copying strings.
 * From CPP02: This is virtual, so derived classes can override it.
 *
 * Pseudocode:
 * 1. Check if we have enough energy
 * 2. Spend 1 energy point
 * 3. Deal _attackDamage damage
 * 4. Print the action
 */
void	ClapTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
		return ;
	}
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

/*
 * takeDamage():
 * ClapTrap takes damage from an attack.
 * Can't have negative hit points - minimum is 0.
 * From CPP01: We use unsigned int to prevent negative values naturally.
 */
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > amount)
		_hitPoints -= amount;
	else
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " damage! HP: " << _hitPoints << std::endl;
}

/*
 * beRepaired():
 * ClapTrap repairs itself, gaining health.
 * Costs 1 energy point.
 */
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to repair!" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself, gaining "
		<< amount << " HP! Total HP: " << _hitPoints << std::endl;
}

/*
 * Getter methods (const):
 * From CPP02: Good practice to mark methods const when they don't modify state.
 * From CPP00: These are simple accessors for encapsulation.
 */
const std::string	&ClapTrap::getName(void) const
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}
