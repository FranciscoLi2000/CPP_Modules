#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

/*
 * CPP03 - Exercise 02 VERSION: ScavTrap with Virtual Inheritance
 *
 * Same as FragTrap: use "virtual public" instead of just "public".
 * class ScavTrap : virtual public ClapTrap
 *
 * This ensures that ClapTrap is inherited virtually,
 * allowing DiamondTrap to inherit from both without duplication.
 */

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &src);
	ScavTrap &operator=(const ScavTrap &rhs);
	~ScavTrap(void);

	virtual void	attack(const std::string &target);
	void	guardGate(void);

private:
};

#endif
