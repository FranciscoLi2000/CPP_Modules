#ifndef AXE_HPP
#define AXE_HPP

/*
 * Axe: A concrete weapon implementation.
 * Inherits from abstract Weapon class.
 * Must implement the pure virtual attack() method.
 */

#include "Weapon.hpp"

class Axe : public Weapon
{
public:
	Axe(const std::string &name);
	~Axe(void);

	/*
	 * Implementation of pure virtual function attack().
	 * This is what makes Axe a concrete (instantiable) class.
	 * If Axe didn't implement attack(), Axe would also be abstract.
	 */
	virtual void	attack(void) const;
};

#endif
