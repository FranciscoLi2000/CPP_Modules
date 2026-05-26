/*
 * Gun Implementation:
 * A concrete weapon that shoots.
 */

#include "Gun.hpp"
#include <iostream>

/*
 * Gun Constructor:
 * Call Weapon constructor with name and type "GUN".
 */
Gun::Gun(const std::string &name) : Weapon(name, "GUN")
{
	std::cout << "Gun " << _name << " is loaded and ready!" << std::endl;
}

Gun::~Gun(void)
{
	std::cout << "Gun " << _name << " is destroyed!" << std::endl;
}

/*
 * Gun::attack():
 * Implements the virtual attack() method.
 * This is what happens when a Gun attacks.
 * Different behavior from Axe, even though both inherit from Weapon!
 * This is polymorphism in action.
 */
void	Gun::attack(void) const
{
	std::cout << _name << " (GUN) shoots bang bang!" << std::endl;
}
