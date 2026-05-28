#ifndef ANIMAL_HPP
#define ANIMAL_HPP

/*
 * Exercise 00 starts the module 04 journey:
 * a base class owns common state, while derived classes specialize behavior.
 */

#include <string>

class Animal
{
public:
	/*
	 * The base class is concrete here, so we can compare the generic
	 * makeSound() behavior with Dog and Cat overrides.
	 */
	Animal(void);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal(void);

	std::string const &getType(void) const;
	virtual void	makeSound(void) const;

protected:
	std::string type;
};

#endif
