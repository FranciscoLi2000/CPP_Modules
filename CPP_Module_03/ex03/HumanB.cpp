#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

/*
 * HumanB Constructor:
 * Initialize with a name and no weapon.
 */
HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL)
{
	std::cout << "HumanB " << _name << " is constructed!" << std::endl;
}

/*
 * HumanB Destructor:
 * HumanB doesn't own the weapon (it's just a reference).
 * So we don't delete _weapon.
 * From CPP01: Understanding pointer ownership is important.
 */
HumanB::~HumanB(void)
{
	std::cout << "HumanB " << _name << " is destroyed!" << std::endl;
}

/*
 * setWeapon():
 * HumanB picks up a weapon (pointer to Weapon).
 * From CPP01: Pointers allow indirection and polymorphism.
 */
void	HumanB::setWeapon(Weapon *weapon)
{
	_weapon = weapon;
	std::cout << "HumanB " << _name << " picks up a weapon!" << std::endl;
}

/*
 * attack():
 * HumanB attacks.
 * If HumanB has a weapon, call its attack() method.
 * If no weapon, can't attack.
 *
 * Key Polymorphism Concept:
 * We have a Weapon* that could point to an Axe, Gun, or any other Weapon.
 * When we call _weapon->attack(), the virtual function mechanism ensures
 * the correct implementation is called based on the actual object type!
 *
 * This is called "dynamic dispatch" or "late binding."
 * From CPP02: This is why we made attack() virtual in Weapon.
 */
void	HumanB::attack(void) const
{
	if (_weapon == NULL)
	{
		std::cout << "HumanB " << _name << " cannot attack (no weapon)!" << std::endl;
		return ;
	}
	std::cout << "HumanB " << _name << " attacks with ";
	_weapon->attack();
}
