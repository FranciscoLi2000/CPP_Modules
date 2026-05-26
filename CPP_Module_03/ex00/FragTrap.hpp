#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

/*
 * CPP03 - Exercise 00: FragTrap
 *
 * Introduction to Inheritance:
 * FragTrap inherits from ClapTrap using public inheritance.
 * This means:
 * - FragTrap IS-A ClapTrap
 * - public members of ClapTrap are public in FragTrap
 * - protected members of ClapTrap are protected in FragTrap
 * - private members are not accessible (even to FragTrap)
 *
 * From CPP00, CPP01, CPP02:
 * - Encapsulation: Hide implementation details (private members)
 * - Inheritance: Reuse code from base class
 * - Virtual functions: Allow customization in derived classes
 *
 * FragTrap has higher HP (100) and different attack behavior (special attack).
 */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	/*
	 * Constructor:
	 * Calls the parent class (ClapTrap) constructor using initializer list.
	 * Then initializes FragTrap-specific members.
	 * Initialization order: Base class first, then derived class.
	 */
	FragTrap(const std::string &name);

	/*
	 * Copy Constructor:
	 * When copying a FragTrap, also copy the base class (ClapTrap) part.
	 * This is important in inheritance: both parts must be copied.
	 */
	FragTrap(const FragTrap &src);

	/*
	 * Assignment Operator:
	 * When assigning, assign both base and derived parts.
	 * From CPP02: Always return *this for chaining.
	 */
	FragTrap &operator=(const FragTrap &rhs);

	/*
	 * Destructor:
	 * Called when FragTrap is destroyed.
	 * The base class destructor is called automatically after this.
	 */
	~FragTrap(void);

	/*
	 * Overriding attack():
	 * From CPP02: Virtual functions allow derived classes to change behavior.
	 * FragTrap has a special attack that costs 1 EP and can hit any target.
	 */
	virtual void	attack(const std::string &target);

	/*
	 * FragTrap Special Ability:
	 * high_five(): Offer a high five to another entity (for fun!).
	 * This is a method only FragTrap has, not in the base class.
	 */
	void	highFiveWithGuys(void);

private:
	/*
	 * Private member:
	 * Not accessible even to derived classes, keeps data truly private.
	 */
};

#endif
