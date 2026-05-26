/*
 * DiamondTrap Implementation
 *
 * This is the most complex part of the exercise.
 * We need to handle multiple inheritance and virtual constructors.
 *
 * Key Challenge: DiamondTrap inherits from both FragTrap and ScavTrap.
 * But FragTrap and ScavTrap both inherit from ClapTrap.
 *
 * Constructor Order:
 * 1. ClapTrap constructor (virtual base)
 * 2. FragTrap constructor
 * 3. ScavTrap constructor
 * 4. DiamondTrap constructor
 *
 * From CPP02: We learned about constructor initialization and chaining.
 * Now with multiple inheritance, the pattern is:
 * DiamondTrap::DiamondTrap(name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
 *
 * The virtual keyword ensures ClapTrap is constructed only once,
 * even though DiamondTrap inherits from it through two paths.
 */

#include "DiamondTrap.hpp"
#include <iostream>

/*
 * DiamondTrap Constructor:
 * Initialize BOTH FragTrap and ScavTrap, which handle ClapTrap through virtual inheritance.
 * Then set DiamondTrap-specific members.
 *
 * Note: We pass name to FragTrap and ScavTrap so they can set up properly.
 * DiamondTrap gets its own _name member, distinct from ClapTrap's _name.
 */
DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
	/*
	 * Customize DiamondTrap stats.
	 * Combine the best of both worlds (or something in between):
	 * - HP from FragTrap/ScavTrap: 100
	 * - EP from ScavTrap: 50
	 * - AD: Custom value
	 */
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " is constructed!" << std::endl;
}

/*
 * Copy Constructor:
 * Call copy constructors of FragTrap and ScavTrap.
 * They handle ClapTrap through virtual inheritance.
 */
DiamondTrap::DiamondTrap(const DiamondTrap &src)
	: ClapTrap(src), FragTrap(src), ScavTrap(src), _name(src._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

/*
 * Assignment Operator:
 * Assign all parent classes and DiamondTrap-specific members.
 * This is complex with multiple inheritance but follows the same pattern.
 */
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		/*
		 * Assign base classes.
		 * We only need to call ClapTrap's operator= because
		 * FragTrap and ScavTrap will also call it through virtual inheritance.
		 * To be safe and explicit, we can call both:
		 */
		ClapTrap::operator=(rhs);
		/* Technically, we could also do:
		 * FragTrap::operator=(rhs);
		 * ScavTrap::operator=(rhs);
		 * But they would try to assign ClapTrap twice.
		 * Virtual inheritance handles this, but one call is sufficient.
		 */
		_name = rhs._name;
	}
	return (*this);
}

/*
 * Destructor:
 * Called when DiamondTrap is destroyed.
 * Destruction order: DiamondTrap -> ScavTrap -> FragTrap -> ClapTrap
 * (reverse of construction order)
 */
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " is destroyed!" << std::endl;
}

/*
 * attack() with Scope Resolution:
 * DiamondTrap inherits attack() from both FragTrap and ScavTrap.
 * The compiler can't decide which one to use: ERROR!
 * Solution: We override it and explicitly choose which parent's method to call.
 *
 * Here we use ScavTrap's attack (knife attack).
 * Alternative: FragTrap::attack(target); for grenade attack.
 *
 * This demonstrates why virtual inheritance and scope resolution are important.
 */
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

/*
 * whoAmI():
 * Prints information about DiamondTrap.
 * Shows how to access inherited members and resolve ambiguities.
 */
void	DiamondTrap::whoAmI(void)
{
	/*
	 * Important: DiamondTrap has its own _name member (a string).
	 * ClapTrap also has a _name member (also a string).
	 * They are different! This is intentional in the 42 curriculum.
	 *
	 * DiamondTrap._name: the custom name set for DiamondTrap
	 * ClapTrap._name: passed through from construction
	 *
	 * To access ClapTrap's _name explicitly, use ClapTrap::_name or getName()
	 */
	std::cout << "I am DiamondTrap " << _name << " and my ClapTrap name is "
		<< ClapTrap::_name << "!" << std::endl;
	std::cout << "HP: " << _hitPoints << ", EP: " << _energyPoints
		<< ", AD: " << _attackDamage << std::endl;
}
