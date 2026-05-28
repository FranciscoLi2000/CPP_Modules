#ifndef AMATERIA_HPP
#define AMATERIA_HPP

/*
 * AMateria is the abstract base for all concrete magical items.
 */

#include <string>

class ICharacter;

class AMateria
{
public:
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria(void);

	std::string const &getType(void) const;
	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target);

protected:
	std::string _type;
};

#endif
