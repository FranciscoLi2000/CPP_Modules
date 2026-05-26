/*
 * From CPP00: Include files to use standard I/O.
 * From CPP01: We understand references now (no copying strings).
 * From CPP02: Remember the Orthodox Canonical Form.
 */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

/*
 * In ex00 (FragTrap), we had a separate ClapTrap.cpp.
 * For consistency, we do the same here: ScavTrap.cpp includes its implementation.
 *
 * From CPP02: Classes in C++ (unlike Java or Python) need separate declaration (.hpp)
 * and implementation (.cpp) files for large projects.
 */

#include <iostream>

/*
 * ScavTrap Constructor:
 * Initialize base class, then set ScavTrap-specific stats.
 *
 * From CPP02: Use member initialization list for efficiency.
 * Syntax: DerivedClass::DerivedClass(param) : BaseClass(param), ...
 */
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	/*
	 * ClapTrap constructor already ran, setting default stats.
	 * Now we override with ScavTrap-specific values.
	 * ScavTrap has:
	 * - 100 HP (like FragTrap)
	 * - 50 EP (more than FragTrap)
	 * - 20 AD (less than FragTrap)
	 */
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " is constructed!" << std::endl;
}

/*
 * Copy Constructor:
 * From CPP02: When copying objects, we must copy all members.
 * In inheritance, we call the base class copy constructor.
 */
ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

/*
 * Assignment Operator:
 * From CPP02: Orthodox Canonical Form requires this.
 * Must call base class operator=, check self-assignment, and return *this.
 *
 * In inheritance, the pattern is:
 * 1. Check self-assignment (this != &rhs)
 * 2. Call base class operator= via ClapTrap::operator=(rhs)
 * 3. Assign ScavTrap-specific members (if any)
 * 4. Return *this
 */
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		/*
		 * No ScavTrap-specific members to assign.
		 * All state is inherited from ClapTrap.
		 */
	}
	return (*this);
}

/*
 * Destructor:
 * Called when ScavTrap is destroyed.
 * Base class destructor (ClapTrap::~ClapTrap) runs automatically after.
 *
 * From CPP02: Destructor chaining is important in polymorphic classes.
 * In this simple case, ClapTrap destructor will also print its destruction message.
 */
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " is destroyed!" << std::endl;
}

/*
 * Overridden attack():
 * From CPP02: Virtual functions allow customization.
 * This is a key concept: same method name, different implementations.
 *
 * FragTrap throws grenades (30 damage).
 * ScavTrap throws knives (20 damage).
 * ClapTrap just attacks (0 damage if not set).
 *
 * This demonstrates polymorphism:
 * When you have a pointer/reference to ClapTrap but the actual object
 * is a ScavTrap, the ScavTrap::attack() version is called!
 *
 * Example:
 * ClapTrap *ptr = new ScavTrap("test");
 * ptr->attack("enemy");  // Calls ScavTrap::attack(), not ClapTrap::attack()
 */
void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy to attack!" << std::endl;
		return ;
	}
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target
		<< " with knives, causing " << _attackDamage
		<< " points of piercing damage!" << std::endl;
}

/*
 * guardGate():
 * ScavTrap's special ability.
 * This method only exists on ScavTrap objects.
 * If you try to call it on a ClapTrap or FragTrap, compilation error!
 * This shows that derived classes can add new methods.
 */
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name
		<< " enters Gate Keeper mode and starts guarding the gate!" << std::endl;
}
