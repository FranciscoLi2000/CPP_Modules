#include "Weapon.hpp"
#include <iostream>

/*
 * Weapon Constructor:
 * Initialize weapon with name and type.
 */
Weapon::Weapon(const std::string &name, const std::string &type)
	: _name(name), _type(type)
{
	std::cout << "Weapon " << _name << " (" << _type << ") is created!" << std::endl;
}

/*
 * Weapon Destructor:
 * Virtual to ensure derived class destructors are called.
 * From CPP02: This is why virtual destructors are critical!
 */
Weapon::~Weapon(void)
{
	std::cout << "Weapon " << _name << " is destroyed!" << std::endl;
}

/*
 * getType():
 * Simple accessor, marked const.
 */
const std::string	&Weapon::getType(void) const
{
	return (_type);
}
