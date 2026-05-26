#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

/*
 * CPP03 - Exercise 01: ScavTrap
 *
 * Another example of single inheritance!
 * Just like FragTrap (ex00), ScavTrap inherits from ClapTrap.
 * But ScavTrap has different stats and special abilities.
 *
 * This exercise reinforces:
 * - How different derived classes can customize behavior differently
 * - Polymorphism: same base interface, different implementations
 * - Virtual functions: each derived class implements its own version
 *
 * Key Difference from FragTrap:
 * - FragTrap: High HP, special attack (grenades)
 * - ScavTrap: Medium stats, special ability (guard_gate)
 *
 * The beauty of inheritance is that both classes reuse ClapTrap's code
 * but customize what they need to.
 */

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	/*
	 * Constructor:
	 * Sets up ScavTrap-specific stats.
	 * ScavTrap has 100 HP, 50 EP, 20 AD.
	 */
	ScavTrap(const std::string &name);

	/*
	 * Copy Constructor:
	 * From CPP02: Following Orthodox Canonical Form.
	 * Remember to call base class copy constructor.
	 */
	ScavTrap(const ScavTrap &src);

	/*
	 * Assignment Operator:
	 * From CPP02: Don't forget self-assignment check and return *this.
	 */
	ScavTrap &operator=(const ScavTrap &rhs);

	/*
	 * Destructor:
	 * Base class destructor is called automatically after this.
	 */
	~ScavTrap(void);

	/*
	 * Overridden attack():
	 * ScavTrap attacks differently than ClapTrap and FragTrap.
	 * From CPP02: Virtual function allows each class to customize behavior.
	 * ScavTrap throws knives!
	 */
	virtual void	attack(const std::string &target);

	/*
	 * ScavTrap Special Ability:
	 * guardGate(): Enters a defensive stance.
	 * This ability is unique to ScavTrap, not inherited or overridden.
	 */
	void	guardGate(void);

private:
	/*
	 * ScavTrap-specific data (if needed).
	 * For now, all state is inherited from ClapTrap.
	 */
};

#endif
