#ifndef WEAPON_HPP
#define WEAPON_HPP

/*
 * Weapon Base Class:
 * Demonstrates the base for polymorphism.
 *
 * From CPP02: Remember virtual functions?
 * Weapon::attack() is virtual, so derived classes can override it.
 */

#include <string>

class Weapon
{
public:
	/*
	 * Constructor:
	 * Initialize weapon with a name and type.
	 */
	Weapon(const std::string &name, const std::string &type);

	/*
	 * Destructor:
	 * Virtual! Important for polymorphism.
	 * When deleting a Weapon* that actually points to a Gun,
	 * the Gun destructor is called first, then Weapon destructor.
	 */
	virtual ~Weapon(void);

	/*
	 * getType():
	 * Accessor for the weapon type (const because it doesn't modify state).
	 */
	const std::string	&getType(void) const;

	/*
	 * attack():
	 * Pure virtual function - MUST be implemented by derived classes.
	 * From CPP02: Pure virtual makes a class abstract.
	 * This forces all weapons to provide their own attack behavior.
	 */
	virtual void	attack(void) const = 0;

protected:
	/*
	 * Protected members:
	 * Accessible to derived classes (Gun, Axe) but not to outside code.
	 */
	std::string	_name;
	std::string	_type;
};

#endif
