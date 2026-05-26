#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

/*
 * Test program for ex02: Multiple Inheritance and the Diamond Problem
 *
 * This demonstrates the most complex inheritance scenario.
 */
int	main(void)
{
	std::cout << "=== Creating a DiamondTrap ===" << std::endl;
	DiamondTrap	diamond("Diamond");

	std::cout << "\n=== Testing whoAmI() ===" << std::endl;
	diamond.whoAmI();

	std::cout << "\n=== Testing Inherited Methods ===" << std::endl;
	std::cout << "Name: " << diamond.getName() << std::endl;
	std::cout << "HP: " << diamond.getHitPoints() << std::endl;
	std::cout << "EP: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "AD: " << diamond.getAttackDamage() << std::endl;

	std::cout << "\n=== Testing attack() (uses ScavTrap's version) ===" << std::endl;
	diamond.attack("enemy");

	std::cout << "\n=== Testing highFiveWithGuys (from FragTrap) ===" << std::endl;
	diamond.highFiveWithGuys();

	std::cout << "\n=== Testing guardGate (from ScavTrap) ===" << std::endl;
	diamond.guardGate();

	std::cout << "\n=== Testing takeDamage ===" << std::endl;
	diamond.takeDamage(30);

	std::cout << "\n=== Testing beRepaired ===" << std::endl;
	diamond.beRepaired(15);

	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	DiamondTrap diamond2(diamond);
	diamond2.whoAmI();

	std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
	DiamondTrap diamond3("Placeholder");
	diamond3 = diamond;
	diamond3.whoAmI();

	std::cout << "\n=== Showing the Diamond is Fixed with Virtual Inheritance ===" << std::endl;
	/*
	 * With virtual inheritance, DiamondTrap has only ONE ClapTrap data,
	 * shared between FragTrap and ScavTrap.
	 *
	 * Without virtual inheritance:
	 * - FragTrap would have its own copy of ClapTrap data
	 * - ScavTrap would have its own copy of ClapTrap data
	 * - DiamondTrap would have two copies (ambiguous!)
	 * - Memory waste and confusion
	 *
	 * With virtual inheritance:
	 * - Only one copy of ClapTrap data shared
	 * - No ambiguity
	 * - Correct memory management
	 */
	std::cout << "DiamondTrap has one consistent set of ClapTrap data!" << std::endl;

	std::cout << "\n=== Destructors Called When Going Out of Scope ===" << std::endl;
	return (0);
}
