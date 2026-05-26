#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

/*
 * CPP03 - Exercise 02 VERSION: FragTrap with Virtual Inheritance
 *
 * From ex00, FragTrap inherited normally from ClapTrap:
 * class FragTrap : public ClapTrap
 *
 * Now in ex02, we use VIRTUAL inheritance:
 * class FragTrap : virtual public ClapTrap
 *
 * Why Virtual Inheritance?
 * FragTrap and ScavTrap both inherit from ClapTrap.
 * DiamondTrap inherits from both FragTrap and ScavTrap.
 * Without virtual, ClapTrap data would exist twice!
 *
 * With virtual: ClapTrap exists once, shared between FragTrap and ScavTrap.
 *
 * Key Points:
 * - virtual public keyword declares virtual inheritance
 * - Solves the "Diamond Problem"
 * - Slight performance cost (virtual base pointer) but usually worth it
 */

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &src);
	FragTrap &operator=(const FragTrap &rhs);
	~FragTrap(void);

	virtual void	attack(const std::string &target);
	void	highFiveWithGuys(void);

private:
};

#endif
