#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

/*
 * CPP03 - ClapTrap Base Class
 *
 * From CPP00 and CPP01, we learned:
 * - CPP00: Basic object-oriented concepts and memory management
 * - CPP01: Pointers, references, and dynamic memory allocation
 *
 * Now in CPP03, we combine these with:
 * - Inheritance: Create specialized classes from a base class
 * - Polymorphism: Allow derived classes to override methods
 * - Access control: Use public, protected, and private keywords
 *
 * ClapTrap is a simple robot character class that will be inherited by
 * other classes (FragTrap, ScavTrap, DiamondTrap) in later exercises.
 *
 * Key Learning Points:
 * 1. Base classes define common attributes and methods
 * 2. Derived classes can inherit and extend functionality
 * 3. Protected members are accessible to derived classes but not to outside code
 * 4. Virtual functions allow derived classes to override behavior
 */

#include <iostream>
#include <string>

class ClapTrap
{
public:
	/*
	 * Constructor:
	 * Initializes a ClapTrap with a name and default stats.
	 * Health = 10, Energy Points (EP) = 10, Attack Damage = 0
	 */
	ClapTrap(const std::string &name);

	/*
	 * Copy Constructor:
	 * Creates a copy of another ClapTrap.
	 * Important: Each ClapTrap should be independent.
	 */
	ClapTrap(const ClapTrap &src);

	/*
	 * Assignment Operator:
	 * Assigns one ClapTrap to another.
	 * From CPP02: Orthodox Canonical Form requires this.
	 */
	ClapTrap &operator=(const ClapTrap &rhs);

	/*
	 * Destructor:
	 * Not virtual here because ClapTrap is the base, and we'll handle
	 * virtual destructors in derived classes where needed.
	 */
	~ClapTrap(void);

	/*
	 * attack():
	 * ClapTrap attacks another target.
	 * Costs 1 energy point. Prints attack message.
	 * This is where virtual functions become important:
	 * In CPP02, we learned about virtual functions.
	 * Making this virtual allows derived classes to customize attacks.
	 */
	virtual void	attack(const std::string &target);

	/*
	 * takeDamage():
	 * ClapTrap takes damage from being attacked.
	 * Each point of damage reduces hit points.
	 */
	void	takeDamage(unsigned int amount);

	/*
	 * beRepaired():
	 * ClapTrap repairs itself.
	 * Costs 1 energy point. Restores 10 HP.
	 */
	void	beRepaired(unsigned int amount);

	/*
	 * Getter methods (const because they don't modify state):
	 * From CPP00: Simple accessor methods following good encapsulation.
	 */
	const std::string	&getName(void) const;
	unsigned int		getHitPoints(void) const;
	unsigned int		getEnergyPoints(void) const;
	unsigned int		getAttackDamage(void) const;

protected:
	/*
	 * Protected members:
	 * Not accessible from outside, but accessible to derived classes.
	 * This is a key concept in inheritance:
	 * - Private: only this class
	 * - Protected: this class + derived classes
	 * - Public: anyone
	 */
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif
