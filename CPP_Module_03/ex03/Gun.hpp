#ifndef GUN_HPP
#define GUN_HPP

/*
 * Gun: Another concrete weapon implementation.
 * Inherits from abstract Weapon class.
 * Must implement the pure virtual attack() method.
 */

#include "Weapon.hpp"

class Gun : public Weapon
{
public:
	Gun(const std::string &name);
	~Gun(void);

	/*
	 * Implementation of pure virtual function attack().
	 * This is what makes Gun a concrete (instantiable) class.
	 */
	virtual void	attack(void) const;
};

#endif
