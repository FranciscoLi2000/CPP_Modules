#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

/*
 * Test program for ex00:
 * Demonstrates inheritance and virtual functions.
 * Shows how FragTrap extends ClapTrap.
 */
int	main(void)
{
	std::cout << "=== Creating a FragTrap ===" << std::endl;
	FragTrap	frag("Boom");

	std::cout << "\n=== Testing Inherited Methods ===" << std::endl;
	std::cout << "Name: " << frag.getName() << std::endl;
	std::cout << "HP: " << frag.getHitPoints() << std::endl;
	std::cout << "EP: " << frag.getEnergyPoints() << std::endl;
	std::cout << "AD: " << frag.getAttackDamage() << std::endl;

	std::cout << "\n=== Testing FragTrap-specific Attack ===" << std::endl;
	frag.attack("enemy");

	std::cout << "\n=== Testing Inherited takeDamage ===" << std::endl;
	frag.takeDamage(30);

	std::cout << "\n=== Testing Inherited beRepaired ===" << std::endl;
	frag.beRepaired(20);

	std::cout << "\n=== Testing FragTrap-specific highFiveWithGuys ===" << std::endl;
	frag.highFiveWithGuys();

	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	FragTrap frag2(frag);
	std::cout << "frag2 name: " << frag2.getName() << std::endl;

	std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
	FragTrap frag3("Placeholder");
	frag3 = frag;
	std::cout << "frag3 name after assignment: " << frag3.getName() << std::endl;

	std::cout << "\n=== Destructors Called When Going Out of Scope ===" << std::endl;
	return (0);
}
