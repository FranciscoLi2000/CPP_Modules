#ifndef HUMANB_HPP
#define HUMANB_HPP

/*
 * CPP03 - Exercise 03: Advanced Polymorphism
 *
 * This exercise demonstrates polymorphic behavior with weapons.
 * From CPP02: We learned about virtual functions and polymorphism.
 *
 * Now we see a more realistic example:
 * - A Weapon is a base class (abstract behavior)
 * - Specific weapons (Axe, Gun) inherit from Weapon
 * - A HumanB can hold a Weapon* and attack using it
 *
 * When HumanB attacks, it calls the Weapon's attack() method.
 * Due to virtual functions, the correct weapon type's attack() is called!
 *
 * Key Learning:
 * - Polymorphism lets us write code that works with base class pointers/references
 * - The actual type is determined at runtime (dynamic dispatch)
 * - This makes code flexible and extensible
 */

#include <string>

class Weapon;  // Forward declaration

class HumanB
{
public:
	/*
	 * Constructor:
	 * HumanB doesn't start with a weapon (null pointer).
	 */
	HumanB(const std::string &name);

	/*
	 * Destructor:
	 * HumanB doesn't own the weapon, so no delete needed.
	 * (In a real game, you might want to manage weapon ownership)
	 */
	~HumanB(void);

	/*
	 * setWeapon():
	 * HumanB can pick up or change weapons.
	 * Uses a pointer to Weapon, so any derived weapon works!
	 */
	void	setWeapon(Weapon *weapon);

	/*
	 * attack():
	 * HumanB attacks using whatever weapon it has.
	 * If no weapon, print "can't attack".
	 * If weapon exists, call weapon->attack().
	 *
	 * Key: This method doesn't know or care what type of weapon it is!
	 * It just calls the Weapon interface. Due to virtual functions,
	 * the right implementation is called.
	 */
	void	attack(void) const;

private:
	std::string	_name;
	Weapon		*_weapon;
};

#endif
