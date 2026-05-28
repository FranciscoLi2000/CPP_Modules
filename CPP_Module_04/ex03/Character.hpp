#ifndef CHARACTER_HPP
#define CHARACTER_HPP

/*
 * Character owns up to four equipped Materia pointers.
 */

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character(std::string const &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	virtual ~Character(void);

	virtual std::string const &getName(void) const;
	virtual void	equip(AMateria *m);
	virtual void	unequip(int idx);
	virtual void	use(int idx, ICharacter &target);

private:
	void	clearInventory(void);
	void	copyInventory(const Character &other);

	std::string	_name;
	AMateria	*_inventory[4];
};

#endif
