#include "Weapon.hpp"
#include "Axe.hpp"
#include "Gun.hpp"
#include "HumanB.hpp"
#include <iostream>

/*
 * Test program for ex03: Advanced Polymorphism
 *
 * Demonstrates:
 * - Abstract base class (Weapon with pure virtual attack)
 * - Concrete implementations (Axe, Gun)
 * - Polymorphic usage through base class pointers
 * - Virtual function dispatch (the right method is called at runtime)
 */
int	main(void)
{
	std::cout << "=== Creating Weapons ===" << std::endl;
	/*
	 * Create concrete weapons (Axe and Gun).
	 * Cannot create Weapon directly - it's abstract (has pure virtual).
	 */
	Axe		axe("Iron Axe");
	Gun		gun("Colt 45");

	std::cout << "\n=== Creating HumanB ===" << std::endl;
	HumanB	bob("Bob");

	std::cout << "\n=== Bob without a weapon ===" << std::endl;
	bob.attack();

	std::cout << "\n=== Bob picks up the Axe ===" << std::endl;
	bob.setWeapon(&axe);
	bob.attack();

	std::cout << "\n=== Bob switches to the Gun ===" << std::endl;
	bob.setWeapon(&gun);
	bob.attack();

	std::cout << "\n=== Demonstrating Polymorphism ===" << std::endl;
	/*
	 * Key insight:
	 * HumanB's attack() doesn't know if it has an Axe or Gun.
	 * It just has a Weapon* pointer.
	 * But when it calls _weapon->attack(), the correct implementation runs!
	 *
	 * This is dynamic dispatch (late binding):
	 * The actual type is determined at runtime, not compile time.
	 *
	 * From CPP02: This is why we mark attack() virtual in Weapon.
	 * Without virtual, Weapon::attack() would be called (but it's pure virtual,
	 * so that's not possible). With virtual, the correct derived class method is called.
	 *
	 * Array of weapon pointers would work too:
	 * Weapon *weapons[2];
	 * weapons[0] = &axe;
	 * weapons[1] = &gun;
	 * for (int i = 0; i < 2; i++)
	 *     weapons[i]->attack();  // Calls correct attack based on actual type!
	 */

	std::cout << "\n=== Destructors (in reverse order) ===" << std::endl;
	return (0);
}
