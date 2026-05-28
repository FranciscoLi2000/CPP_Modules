#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

/*
 * The final exercise recaps inheritance, interfaces, polymorphism, and deep copy.
 */
int	main(void)
{
	std::cout << "=== Learning Materia templates ===" << std::endl;

	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n=== Creating characters ===" << std::endl;

	ICharacter	*me = new Character("me");
	ICharacter	*bob = new Character("bob");

	AMateria	*tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\n=== Using materias ===" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n=== Copying a character deeply ===" << std::endl;

	Character	clone(*static_cast<Character *>(me));
	clone.use(0, *bob);
	clone.use(1, *bob);

	std::cout << "\n=== Unequip leaves the slot empty but does not delete ===" << std::endl;
	me->unequip(0);
	me->use(0, *bob);

	std::cout << "\n=== MateriaSource copy and unknown materia test ===" << std::endl;

	MateriaSource	sourceCopy(*static_cast<MateriaSource *>(src));
	AMateria	*unknown = sourceCopy.createMateria("fire");
	if (unknown == NULL)
		std::cout << "Unknown materia request returned NULL" << std::endl;

	delete unknown;
	delete bob;
	delete me;
	delete src;
	return (0);
}
