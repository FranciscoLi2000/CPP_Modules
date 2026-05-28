#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	int	i;

	for (i = 0; i < 4; ++i)
		_stored[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	int	i;

	for (i = 0; i < 4; ++i)
		_stored[i] = NULL;
	copyStorage(other);
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		clearStorage();
		copyStorage(other);
	}
	std::cout << "MateriaSource assignment operator called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	clearStorage();
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	if (m == NULL)
		return ;
	for (i = 0; i < 4; ++i)
	{
		if (_stored[i] == NULL)
		{
			_stored[i] = m->clone();
			delete m;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int	i;

	for (i = 0; i < 4; ++i)
	{
		if (_stored[i] != NULL && _stored[i]->getType() == type)
			return (_stored[i]->clone());
	}
	return (NULL);
}

void MateriaSource::clearStorage(void)
{
	int	i;

	for (i = 0; i < 4; ++i)
	{
		delete _stored[i];
		_stored[i] = NULL;
	}
}

void MateriaSource::copyStorage(const MateriaSource &other)
{
	int	i;

	for (i = 0; i < 4; ++i)
	{
		if (other._stored[i] != NULL)
			_stored[i] = other._stored[i]->clone();
		else
			_stored[i] = NULL;
	}
}
