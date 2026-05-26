#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

/*
 * CPP03 - Exercise 02: DiamondTrap (Multiple Inheritance)
 *
 * This is the most complex inheritance exercise!
 * DiamondTrap inherits from BOTH FragTrap and ScavTrap.
 * Both FragTrap and ScavTrap inherit from ClapTrap.
 *
 * This creates the "Diamond Problem":
 *
 *      ClapTrap
 *       /    \
 *   FragTrap  ScavTrap
 *       \    /
 *      DiamondTrap
 *
 * Without Virtual Inheritance:
 * - DiamondTrap would have TWO copies of ClapTrap members!
 * - Confusion: is DiamondTrap._name from ClapTrap or ClapTrap?
 * - Memory waste: duplicate ClapTrap data
 *
 * With Virtual Inheritance:
 * - DiamondTrap has only ONE copy of ClapTrap members
 * - Clear which methods/members are being used
 * - Proper memory management
 *
 * Key Syntax:
 * class DiamondTrap : public FragTrap, public ScavTrap
 * But FragTrap and ScavTrap must use VIRTUAL inheritance from ClapTrap
 *
 * From CPP02: This shows why virtual functions and inheritance are powerful.
 * From CPP00/CPP01: Good memory management is critical.
 */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	/*
	 * Constructor:
	 * Call constructors of BOTH FragTrap and ScavTrap.
	 * But be careful: both try to construct ClapTrap!
	 * With virtual inheritance, ClapTrap is constructed only once,
	 * but we must explicitly call it in the most-derived class.
	 */
	DiamondTrap(const std::string &name);

	/*
	 * Copy Constructor:
	 * Copy both FragTrap and ScavTrap parts.
	 */
	DiamondTrap(const DiamondTrap &src);

	/*
	 * Assignment Operator:
	 * Assign both FragTrap and ScavTrap parts.
	 */
	DiamondTrap &operator=(const DiamondTrap &rhs);

	/*
	 * Destructor:
	 * Destructors run in reverse order: DiamondTrap -> ScavTrap -> FragTrap -> ClapTrap
	 */
	~DiamondTrap(void);

	/*
	 * attack():
	 * DiamondTrap inherits attack() from both FragTrap and ScavTrap.
	 * Which one does it use? AMBIGUOUS!
	 * Solution: Explicitly override and choose which one to call,
	 * or scope it: FragTrap::attack() or ScavTrap::attack()
	 *
	 * Here, we use ScavTrap's attack.
	 */
	virtual void	attack(const std::string &target);

	/*
	 * whoAmI():
	 * Prints information about DiamondTrap.
	 * Demonstrates how to access members without ambiguity.
	 */
	void	whoAmI(void);

private:
	std::string	_name;
};

#endif
