#ifndef CURE_HPP
#define CURE_HPP

/*
 * Cure is the second concrete Materia from the subject examples.
 */

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	virtual ~Cure(void);

	virtual AMateria	*clone(void) const;
	virtual void		use(ICharacter &target);
};

#endif
