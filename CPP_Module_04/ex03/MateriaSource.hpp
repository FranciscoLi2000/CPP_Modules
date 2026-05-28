#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

/*
 * MateriaSource stores Materia templates and clones them on demand.
 */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	virtual ~MateriaSource(void);

	virtual void	learnMateria(AMateria *m);
	virtual AMateria	*createMateria(std::string const &type);

private:
	void	clearStorage(void);
	void	copyStorage(const MateriaSource &other);

	AMateria	*_stored[4];
};

#endif
