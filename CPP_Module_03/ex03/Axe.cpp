/*
 * Axe Implementation:
 * A concrete weapon that swings.
 */

#include "Axe.hpp"
#include <iostream>

/*
 * Axe Constructor:
 * Call Weapon constructor with name and type "AXE".
 * Axe-specific initialization (if any) goes here.
 */
Axe::Axe(const std::string &name) : Weapon(name, "AXE")
{
	std::cout << "Axe " << _name << " is sharpened and ready!" << std::endl;
}

Axe::~Axe(void)
{
	std::cout << "Axe " << _name << " is destroyed!" << std::endl;
}

/*
 * Axe::attack():
 * Implements the virtual attack() method.
 * This is what happens when an Axe attacks.
 * Only called through a Weapon* pointing to an Axe object!
 */
void	Axe::attack(void) const
{
	std::cout << _name << " (AXE) slashes with a sharp swing!" << std::endl;
}
