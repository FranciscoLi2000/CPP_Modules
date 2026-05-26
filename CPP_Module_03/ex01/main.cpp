#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

/*
 * Copy ClapTrap.hpp and ClapTrap.cpp from ex00 to this directory
 * before compiling this exercise!
 *
 * Test program for ex01:
 * Demonstrates that ScavTrap is a valid ClapTrap but with different behavior.
 */
int	main(void)
{
	std::cout << "=== Creating a ScavTrap ===" << std::endl;
	ScavTrap	scav("Blaster");

	std::cout << "\n=== Testing Inherited Getters ===" << std::endl;
	std::cout << "Name: " << scav.getName() << std::endl;
	std::cout << "HP: " << scav.getHitPoints() << std::endl;
	std::cout << "EP: " << scav.getEnergyPoints() << std::endl;
	std::cout << "AD: " << scav.getAttackDamage() << std::endl;

	std::cout << "\n=== Testing ScavTrap-specific Attack ===" << std::endl;
	scav.attack("enemy");

	std::cout << "\n=== Testing ScavTrap Special Ability ===" << std::endl;
	scav.guardGate();

	std::cout << "\n=== Testing Inherited takeDamage ===" << std::endl;
	scav.takeDamage(50);

	std::cout << "\n=== Testing Inherited beRepaired ===" << std::endl;
	scav.beRepaired(25);

	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	ScavTrap scav2(scav);

	std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
	ScavTrap scav3("Temporary");
	scav3 = scav;

	std::cout << "\n=== Polymorphism: Pointer to Base Class ===" << std::endl;
	/*
	 * From CPP02: Virtual functions enable polymorphism.
	 * We can have a pointer to ClapTrap that actually points to a ScavTrap.
	 * When we call attack(), the ScavTrap version is called!
	 */
	ClapTrap *ptr = &scav;
	ptr->attack("target");  // Calls ScavTrap::attack()

	std::cout << "\n=== Destructors Called When Going Out of Scope ===" << std::endl;
	return (0);
}
