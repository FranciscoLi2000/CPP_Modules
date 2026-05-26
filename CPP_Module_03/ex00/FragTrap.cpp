#include "FragTrap.hpp"
#include <iostream>

/*
 * FragTrap Constructor:
 * Key syntax: FragTrap::FragTrap(name) : ClapTrap(name)
 * This calls ClapTrap's constructor with the name parameter.
 * Then sets FragTrap-specific attributes.
 *
 * From CPP02: Member initialization list is efficient and proper.
 */
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	/*
	 * After ClapTrap is constructed, we customize FragTrap's stats:
	 * FragTrap has more HP but same attack damage (for now)
	 */
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " is constructed!" << std::endl;
}

/*
 * Copy Constructor:
 * When copying a FragTrap, we must copy the ClapTrap base class too.
 * Syntax: FragTrap::FragTrap(src) : ClapTrap(src)
 * This calls ClapTrap's copy constructor with the src object.
 */
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

/*
 * Assignment Operator:
 * When assigning, use ClapTrap::operator= to assign the base class part.
 * Then assign any FragTrap-specific members (none in this case).
 * From CPP02: Always check self-assignment with this != &rhs.
 */
FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		/*
		 * Assign FragTrap-specific members here if any.
		 * For now, all state is inherited from ClapTrap.
		 */
	}
	return (*this);
}

/*
 * Destructor:
 * Called when FragTrap is destroyed.
 * The order is:
 * 1. FragTrap destructor runs first (this one)
 * 2. ClapTrap destructor runs automatically after
 * This is called "destructor chaining."
 */
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " is destroyed!" << std::endl;
}

/*
 * Overridden attack():
 * From CPP02: Virtual functions let derived classes change behavior.
 * FragTrap's attack is similar to ClapTrap but with custom damage.
 * This demonstrates polymorphism: same function name, different behavior.
 */
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

/*
 * highFiveWithGuys():
 * A special ability unique to FragTrap.
 * This method is only available on FragTrap objects, not on ClapTrap or ScavTrap.
 * This shows how derived classes can add new functionality.
 */
void	FragTrap::highFiveWithGuys(void)
{
	std::cout << "FragTrap " << _name
		<< " offers a high five to everyone around! Give me a high five!" << std::endl;
}
